# C-Tutorials-Database-Manager
Software application to help you manage your tutorials and create watch lists on your way to be a C++ master.

Main features:
- The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.
    - Admin mode: the application will have a database , which holds all the tutorials; admin can add a new tutorial, delete a tutorial and update the information                     of a tutorial. 
    - User mode: the user can create a watch list with the tutorials that he/she wants to watch. 
                 - The application will allow the user to:
                    * View the tutorials
                    * See the tutorials in the database having a given presenter (if the presenter name is empty, see all the tutorials)
                    * Choose whether to add it to his/her tutorial watch list or not .
                    * Delete a tutorial from the watch list; when deleting a tutorial from the watch list, the user can also rate the tutorial (with a like)
                    * See the watch list.

- Store data in a text file and the watchlist in text, CSV or HTML files
- Creates a GUI using Qt framework
- Implements undo and redo functionality for the add, remove, and update operations

