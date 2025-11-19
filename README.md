# Multi-User Banking System in C

A simple command-line banking application written in C that allows multiple users to create accounts, manage their finances, and perform basic banking operations with secure PIN authentication.

## 📋 Description

This is a console-based banking system that simulates real-world banking operations. Users can create individual accounts with unique account numbers and PINs, deposit and withdraw money, check balances, and have their data persistently saved to a file. The system supports up to 100 accounts and provides a user-friendly menu-driven interface.

## ✨ Features

- **Multi-User Support**: Create and manage up to 100 different bank accounts
- **Account Creation**: Register new accounts with name, PIN, and initial deposit
- **Secure Access**: PIN-protected account access
- **Banking Operations**:
  - Check account balance
  - Deposit money
  - Withdraw money (with insufficient funds checking)
- **Data Persistence**: All account data is saved to a file and loaded automatically
- **Unique Account Numbers**: Each account gets a unique account number (starting from 1000)
- **Input Validation**: Prevents negative deposits and overdrafts

## 🚀 Getting Started

### Prerequisites

- GCC compiler (or any C compiler)
- Basic knowledge of command-line operations

### Installation

1. Clone or download the repository
2. Navigate to the project directory
3. Compile the program:

```bash
gcc banking-system.c -o bank
```

### Running the Program

```bash
./bank
```

## 📖 How to Use

### Creating a New Account

1. Select option `1` from the main menu
2. Enter your name
3. Create a 4-digit PIN
4. Enter your initial deposit amount
5. **Remember your Account Number and PIN!**

### Accessing Your Account

1. Select option `2` from the main menu
2. Enter your account number
3. Enter your PIN
4. Choose from the account menu:
   - Check Balance
   - Deposit Money
   - Withdraw Money
   - Logout

### Example Usage

```
===== MULTI-USER BANK ACCOUNT SYSTEM =====

----- MAIN MENU -----
1. Create New Account
2. Access Existing Account
3. Exit
Enter your choice: 1

----- CREATE NEW ACCOUNT -----
Enter your name: John Doe
Create your pin: 1234
Enter the initial deposit: 500

✓ Account created successfully!
Your account number is: 1000
Your PIN: 1234
*** PLEASE REMEMBER THESE DETAILS! ***
```

## 🗂️ Project Structure

```
banking-system/
│
├── banking_system.c       # Main source code
├── bank_accounts          # Data file (auto-generated)
└── README.md             # Project documentation
```

## 🔧 Technical Details


### Data Structure

The program uses a `struct` to store account information:

```c
struct bankaccount {
    char name[30];      // Account holder name
    int pin;            // 4-digit PIN
    float balance;      // Current balance
    int accountnum;     // Unique account number
};
```

### File Storage

- Account data is stored in binary format in `bank_accounts` file
- Data is automatically loaded when the program starts
- Data is saved after each transaction (create, deposit, withdraw)

### Key Functions

- `createaccount()` - Register a new bank account
- `accessaccount()` - Login and access account menu
- `deposit()` - Add money to account
- `withdraw()` - Remove money from account
- `checkbalance()` - Display account information
- `savetofile()` - Save all accounts to file
- `loadfromfile()` - Load accounts from file
- `findaccount()` - Search for account by number and PIN

## ⚠️ Limitations

- Maximum of 100 accounts
- No account deletion feature
- No password encryption (PIN stored in plain text)
- Single-session use (not designed for concurrent users)
- No transaction history
- Account numbers cannot be customized

## 🛡️ Security Notes

This is an educational project and should **NOT** be used for real banking operations:

- PINs are stored in plain text
- No encryption is implemented
- No protection against brute-force attacks
- File access is not restricted

## 🔮 Future Enhancements

Possible improvements for the project:

- [ ] Add password encryption (e.g., using hashing)
- [ ] Implement transaction history
- [ ] Add account deletion feature
- [ ] Support for money transfers between accounts
- [ ] Add interest calculation
- [ ] Implement account types (savings, checking)
- [ ] Add email/phone verification
- [ ] Create a GUI version
- [ ] Add multiple currency support
- [ ] Implement admin panel for bank management

## 🐛 Troubleshooting

### "No such account exists" error
- Make sure you're entering the correct account number and PIN
- Check if the account was created successfully
- Delete the `bank_accounts` file and create a new account

### Compilation errors
- Ensure you have GCC installed: `gcc --version`
- Check for typos in the source code
- Make sure all required headers are included

### Data not saving
- Ensure you have write permissions in the directory
- Check if there's enough disk space
- The `bank_accounts` file should be in the same directory as the executable

## 📝 License

This project is created for educational purposes and is free to use and modify.

## 👨‍💻 Author

Created as a learning project to demonstrate:
- File I/O operations in C
- Structure usage and manipulation
- Menu-driven programming
- Basic data validation
- Array management

## 🤝 Contributing

Feel free to fork this project and submit pull requests for improvements!

## 📞 Support

If you encounter any issues or have questions, please create an issue in the repository.

---

**Note**: This is a console-based educational project. For production banking systems, proper security measures, encryption, and compliance with banking regulations are essential.
