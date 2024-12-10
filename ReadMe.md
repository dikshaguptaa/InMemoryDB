# Data Processing and Storage
**In-Memory Key-Value Database with Transactions**

## Description
This project is a simple in-memory key-value database that supports transactions. Transactions allow making temporary changes to the database, which can either be committed (saved) or rolled back (discarded). The main features include:

- beginTransaction(): Starts a new transaction.
- put(key, value): Adds/updates a key-value pair in the transaction.
- get(key): Retrieves the value associated with the key. Returns an error if the key does not exist.
- commit(): Saves the changes made in the current transaction.
- rollback(): Discards the changes made in the current transaction. 


## How to run
1. Clone the repository to your local machine. 
   - git clone <repository-url>
   - cd <repository-folder>
2. Open the project in your preferred IDE (e.g., CLion for C++).
3. Configure the project in your IDE if required (e.g., ensure the correct CMake configuration is loaded in CLion).
3. Build the project by following your IDE's build instructions.
   - In CLion: Click Build > Build Project from the menu.
4. Run the program and observe the output in the terminal.
   - In CLion: Click Run > Run 'main' to execute the program and view the output in the terminal.

## Improvements for Future Assignments
To make this assignment more effective as an official project:
1. Clearly define what should happen in scenarios like calling get(key) for a non-existent key.
2. Add methods like delete(key) to allow students to build a more comprehensive database.
3. Include a keyExists(key) method to let students implement additional checks.
4. Offer sample input and output files to allow students to be confident in their implementation.
5. Provide automated test scripts to standardize evaluation.
6. Introduce a README template or example file to ensure consistent and professional documentation across submissions.
7. Specify how to handle invalid operations, such as attempting to commit or rollback without an active transaction.
8. Connect the assignment to real-world scenarios, such as transaction handling in banking systems, to make it more engaging and relatable.