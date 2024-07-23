#include "authenticate.h"
#include "sha256.h"

int authenticate(char *input) {
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

    for(unsigned int i = 0; i < strlen(input_pass); ++i) {
        input_pass[i] = input_pass[i]/2 + salt[i%salt_len]; //salting
    }

    fp = fopen("../config", "r");
    if(fp == NULL) {
        fp = fopen("../config", "w"); // if the file does not exist, create it and write password: admin
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

    fd = fopen("../config", "r");
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
        //printf("Read pass: %x\n", passSha[i]);
        if(input_pass_sha[i] != passSha[i]) {
            //printf("Password is incorrect!\n");
            fclose(fd);
            return ERROR_WRNG_PASS;
        }
    }
    return SUCCESS_PASS;
}
