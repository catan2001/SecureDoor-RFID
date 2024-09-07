/*MIT License

Copyright (c) 2024 catan2001

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "include/authenticate.h"
#include "include/sha256.h"
#include <QDebug>

int authenticate(const char *input) {
    FILE *fp;
    FILE *fd;
    const char salt[] = "89ZhK$#!__)9mjjjk"; // CHANGE FOR SECURITY REASONS!
    unsigned int passSha[8];
    char default_pass[] = "admin";
    unsigned int default_sha[8];
    unsigned int salt_len = strlen(salt);
    char *input_pass = (char *)malloc(strlen(input) * sizeof(char));
    unsigned int input_pass_sha[8];
    strcpy(input_pass, input); //TODO: change strcpy to better function

    if(mkdir("../config", 0777) < 0)
        qDebug() << "error in mkdir\n";

    for(unsigned int i = 0; i < strlen(input_pass); ++i) {
        input_pass[i] = input_pass[i]/2 + salt[i%salt_len]; //salting
    }

    fp = fopen("../config/config", "r");
    if(fp == NULL) {
        fp = fopen("../config/config", "w"); // if the file does not exist, create it and write password: admin

        if(fp == NULL) {
            free(input_pass);
            return ERROR_FILE;
        };

        for(unsigned int i = 0; i < strlen(default_pass); ++i) {
            default_pass[i] = default_pass[i]/2 + salt[i%salt_len]; //salting
        }

        if(sha_256(default_pass, default_sha) != 0) {
            free(input_pass);
            return ERROR_SHA;
        }
        for(unsigned char i = 0; i < 8; ++i)
          fprintf(fp, "%x", default_sha[i]);
        fclose(fp);
    }

    fd = fopen("../config/config", "r");
    if(fd == NULL) {
        free(input_pass);
        return ERROR_FILE;
    }

    if(sha_256(input_pass, input_pass_sha) != 0) {
        free(input_pass);
        return ERROR_SHA;
    }
    free(input_pass);

    for(unsigned int i = 0; i < 8; ++i) {
        fscanf(fd, "%8x", &passSha[i]);
        if(input_pass_sha[i] != passSha[i]) {
            fclose(fd);
            return ERROR_WRNG_PASS;
        }
    }
    return SUCCESS_PASS;
}
