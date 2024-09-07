# Contents


**Key Features of the Application:**

- **RFID Tag Reading:** Utilizes the MFRC522 sensor to read data from RFID tags or cards, facilitating the authentication process.
  
- **Data Verification:** Checks the read data against a database that contains all registered RFID tags and associated user information. This ensures that only authorized users are granted access.
  
- **User Information Display:** If the user is found in the database, their information is displayed, providing real-time feedback on who is accessing the system.

- **Access History Tracking:** Keeps a record of previous access attempts, allowing administrators to review and monitor access activities over time for security and auditing purposes.

- **Access Rights Management:** Manages access rights based on registered RFID tags, allowing for flexible and dynamic control over who can access specific areas or resources.

- **Database Management:** Includes functionality to add, delete, and update RFID tags and user information in the database, making it easy to maintain and update access permissions as needed.


## **Application Overview**

The application offers an intuitive graphical user interface (GUI) that allows users to easily manage the access control system.

Upon launching the application, a login dialog appears where users must enter a password to access the main window of the application. This initial security step ensures that only authorized users can interact with the application.

After successful authentication, the "MainWindow" opens, designed to provide a clear overview and easy access to all functionalities.

Once users enter the main window, the initial screen offers an intuitive overview of the database or displays relevant information about the last user who accessed the system, depending on the selected menu option.

**Main Window Layout**

Below is a detailed description of the main window:

1. **Navigation Menu (View, Tools, Window, Help):**  
   Located at the top of the window, this menu provides access to additional tools, display settings, window management, and help information.

2. **Left Menu (Clients, Monitor, Add, Search, Settings):**  
   - **Clients and Monitor:** These options allow navigation through different sections of the application, where user data can be viewed, or the status of the RFID reader can be monitored.
   - **Add, Search, and Settings:** The lower part of the menu contains options for adding new users, searching the database, and configuring application settings. This part of the menu can be hidden or shown using the View tab.

3. **Central Display (Table or Access Information):**  
   Depending on whether the Clients or Monitor option in the left menu is active, the central part of the screen displays the corresponding information:
   - If the Clients option is active, a list of users with their details, including name, surname, email, RFID code, and image path, is displayed. This section is crucial for managing the user database and their associated RFID tags.
   - If the Monitor option is active, basic information about the previous user who successfully accessed the system using an RFID tag is displayed.

4. **Right Menu (Options) – Quick Actions:**  
   This section provides quick access to additional options, such as:
   - **Add:** Adding new users and their information.
   - **Remove:** Deleting selected users.
   - **ReScan Tag:** Updating the RFID tag reading.
   - **Hide/Show:** Option to hide or show the right panel.
   - **Save Data:** Option to save the current database to an output file.
   - **Load Data:** Option to load the database from an input file containing the list of all users.

5. **Right Panel – Access History:**  
   This section displays the access history for the current session, showing information about all users who have accessed the system.

**Lower Left Menu**

The lower left menu contains three key options: Add, Search, and Settings. These options provide users with additional functionalities for managing the database, searching for information, and configuring the application settings.

1. **Add:**
   This option is used to add a new user to the database. Administrators can input new user details, including first name, last name, email address, RFID tag, and the path to the user's image using this functionality.
   When "Add" is clicked, the "Add New Client" dialog opens, a dedicated window where new user information is entered. After inputting and confirming the details, the new user is added to the table on the main screen, allowing tracking and management of their access rights.

2. **Search:**
   This option allows quick searches of users within the table on the main screen. Users can easily find specific entries in the database using keywords such as first name, last name, or email address.
   Clicking on "Search" opens the "Search Client" dialog, a window where the search term can be entered. The search results are immediately displayed in the table, highlighting only the relevant entry. Using the "Next" and "Previous" options, users can navigate through the next or previous user that matches the search criteria.

3. **Settings:**
   This option allows the configuration of the basic application settings, including setting the login password for accessing the application. This functionality is crucial for maintaining security and controlling access to the application.
   Clicking on "Settings" opens the "Settings" dialog or a window with password configuration options. Users can change the login password by entering the current password, then the new password, and finally confirming it through the "Confirm" button. The new password state is saved by clicking the "Save" button. The password is stored in a dedicated file located in the application's directory. When the user changes or sets a new password within the application, the system ensures that the password is saved securely using advanced data protection methods. A more detailed description of password storage will be provided later.

This detailed menu structure enhances the application's usability, allowing users to efficiently manage access control settings and database entries while ensuring a secure environment for data handling and access management.

**2.3 Navigation Menu (View, Tools, Window, Help)**

The navigation menu is located at the top of the main window of the application and provides users with access to various options for customizing the display, using additional tools, managing windows, and accessing information about the application. This menu is organized into four main sections: View, Tools, Window, and Help. Clicking on any of these sections opens a dropdown menu.

**View:**

This section allows users to customize the display of the main window of the application. With these options, users can control which interface elements they want to show or hide.

The options in this section include:

- **Show Left Sidebar:** Allows the user to show or hide the left sidebar, which contains options like Add, Search, and Settings.
  
- **Show Right Sidebar:** Allows the user to show or hide the right sidebar, which contains options for adding users, deleting entries, rescanning RFID tags, and other quick actions.

This structure provides users with the flexibility to tailor the application interface to their preferences, improving usability and ensuring that the workspace is organized according to their needs.

**Tools:**

The Tools section provides access to functionalities that facilitate working with the application and allow users to quickly perform specific tasks. The Tools section is shown in Figure 1.7.

Options in this section include:

- **Add New Client:** Opens a dialog for adding a new user to the database. This option allows for quick expansion of the user list with all necessary information.
  
- **Monitor:** Provides access to tracking users and RFID tag activities. When selected, the main window displays relevant information such as the last users who accessed the system or the activity of the RFID system.

- **Search:** Opens a search tool within the user database, enabling quick retrieval of specific entries based on entered criteria.

**Window:**

This section of the menu allows users to manage the size and position of the main application window. The Window section is shown in Figure 1.8.

Options in this section include:

- **Full Screen:** Switches the main window to full screen, providing maximum workspace without interruptions.

- **Normal:** Restores the window to its normal view (standard size), allowing the user to use other applications simultaneously.

- **Minimize:** Minimizes the application window to the taskbar, keeping it open in the background without taking up screen space.

**Help:**

The Help section provides users with access to online resources and documentation that can assist them in using the application, providing technical support, or reporting issues. All options in this section lead to relevant internet links, ensuring quick and easy access to the needed information. The Help section is shown in Figure 1.9.

Options in this section include:

- **Contents:** Opens the online documentation for the application, where users can find detailed instructions for using all the application's functionalities.
  
- **Technical Support:** Directs users to online technical support resources, where they can find answers to frequently asked questions, contact support, or access additional technical information.

*Suboptions:*

- **GitHub Source Code:** This option leads to the application's source code repository on GitHub. Here, users can review the code, report issues, or contribute to development.

- **Readme:** Takes users to the application's README file, which contains essential information about installation, functionalities, and other important notes.

- **About Developer:** Opens a page with information about the application's developer, including contact details.

- **License:** Directs users to the page with information about the application's license, outlining user rights and restrictions.

- **Report Bug:** Allows users to report bugs or issues with the application directly via an email form.