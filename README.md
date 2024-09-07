# SecureDoor

## Introduction

**Project Overview**

This project is part of the "Computer Electronics" course in the fourth year of undergraduate studies at the Faculty of Technical Sciences (FTN). The main components used for this project include a Raspberry Pi, the MFRC522 RFID sensor, and a graphical user interface (GUI) developed in Qt.

A key aspect of the project is the development of a user-friendly GUI using Qt and QtCreator, a powerful cross-platform framework for creating applications with intuitive interfaces. The GUI allows users to interact with the system easily, providing clear feedback and control over access permissions. It displays information such as user details, access status, and a log of access attempts, making the system more accessible and manageable for end-users.

The project demonstrates the practical application of embedded systems, RFID technology, and GUI development, integrating hardware and software components to create a functional security and access management system. Through this project, I gained hands-on experience with microcontroller programming, sensor interfacing, data handling, and GUI design—critical skills in the field of computer electronics and embedded systems.

Key elements of the project include setting up the Raspberry Pi environment, interfacing it with the MFRC522 sensor via SPI communication, and developing a software application that processes data read from RFID tags. The GUI developed in Qt provides an intuitive way to manage access permissions and view access logs, enhancing the overall functionality and user experience.

Additionally, the project explores database management for storing RFID tag information, access logs, and user data, providing a comprehensive approach to managing access permissions and tracking access history. This practical application reinforces theoretical knowledge with practical skills, preparing students for future challenges in the field of embedded systems and electronics.

Overall, the project not only showcases the integration of hardware and software but also emphasizes the importance of secure and efficient data management, making it an excellent learning experience for students in the realm of computer electronics. The use of Qt for the GUI adds a professional touch, making the system more robust and adaptable to various real-world applications. Future enhancements could include connecting the system to physical security devices like locks or alarms, implementing data encryption, or expanding the system to support multiple sensors and remote database management, further improving security and scalability.

---

## About Application

**"SecureDoor" Application Overview**

The "SecureDoor" application provides access control using the MFRC522 RFID sensor. Users can authenticate themselves using RFID cards or tags, and the application verifies the data read from these cards or tags to determine whether access should be granted. A dedicated database stores all registered RFID tags along with associated user information and their respective access permissions. When an RFID tag is presented to the sensor, the application reads the tag's data, checks it against the database, and automatically grants or denies access based on predefined rules and access rights. Additionally, upon successful access, further actions or notifications can be triggered as needed.

**Key Features of the Application:**

- **RFID Tag Reading:** Utilizes the MFRC522 sensor to read data from RFID tags or cards, facilitating the authentication process.
  
- **Data Verification:** Checks the read data against a database that contains all registered RFID tags and associated user information. This ensures that only authorized users are granted access.
  
- **User Information Display:** If the user is found in the database, their information is displayed, providing real-time feedback on who is accessing the system.

- **Access History Tracking:** Keeps a record of previous access attempts, allowing administrators to review and monitor access activities over time for security and auditing purposes.

- **Access Rights Management:** Manages access rights based on registered RFID tags, allowing for flexible and dynamic control over who can access specific areas or resources.

- **Database Management:** Includes functionality to add, delete, and update RFID tags and user information in the database, making it easy to maintain and update access permissions as needed.

This application, with minor modifications, is ideal for access control systems, security systems, or any other scenarios requiring authentication and management of access rights using RFID technology. It can be adapted to various use cases, such as office entry systems, secured lab access, or restricted area management, providing a scalable and customizable solution for enhancing security and controlling access effectively. 

Additionally, potential enhancements could include integrating alert mechanisms for unauthorized access attempts, connecting with physical security devices such as locks or alarms, and implementing encryption for sensitive data to further secure the overall system. These improvements would make "SecureDoor" a comprehensive and robust access management solution adaptable to a wide range of applications.
