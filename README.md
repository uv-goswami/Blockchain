# Blockchain
## Structure:
- This project implements a simple blockchain data structure consisting of a series of blocks linked together cryptographically. Each Block contains transaction data such as a timestamp, reference to the previous block's Hash, Senders' and Receivers' address, etc.
## Dependencies:
- Require a C++ compiler
- Uses the 'sha256.h' library of SHA-256 hashing.
# Components:
## Block.h:
- Defines the 'Block' class representing the individual block in the blockchain.
- Includes attributes such as index, nonce, timestamp, sender and receiver, etc.
## Block.cpp:
- Implements the functionalities of the 'Block' class, including block creation, mining and hash calculations.
## Blockchain.h:
- Defines the 'Blockchain' class responsible for linking the blocks and managing the blockchain.
## Blockchain.cpp:
- Implements the functionality of the 'Blockchain; class, including block addition and retrival.
## main.cpp:
- Contains the main program demonstrating the usage of the 'Blockcahin' project.
# Usage:
- Clone the repository to your local machine.
- Complie the source file using a c++ complier(e.g., g++) to generate the executable.
# Output:
## Add Transaction:
![](https://github.com/uv-goswami/Blockchain/blob/main/output/01_add_transaction.png)
## View Blockchain:
![](https://github.com/uv-goswami/Blockchain/blob/main/output/02_view_BlockChain.png)
<hr></hr>


## Let's go in more details:

# .h files
- The '.h' file is a header file in c++, which typically contains declarations of classes, functions, and variables that are defined in corresponding source file('.cpp' file).
- '.h' or header files serves several purposes:
    * Encapsulation: Header files allow for encapsulation by separating the interface (what is visible to users of the code) from the       implementation (how the code works internally). This promotes modularity and helps in managing complexity. In general,                encapsulation is a process of wrapping similar code in one place, in our case inside Class.
    * Header files contains declaration of classes, functions, variables, and constants.
    * Managing Dependencies: Header files help in managing dependencies b/w different parts of the program.
- If header files are not used:
    * Duplications of classes,functions and variables which would increase liklihood of error.
    * Reduce the readibility of the program.

# Block.h
```
#include <iostream>
#include <cstdint>                              //For fixed-width integer types like 'size)_t'
#include <string>                               //For String manupaluton and storage.
#include <ctime> 
```
- Include Directives:
  * '#include <iostream>': Includes the input/output stream library, which is necessary for handling input and output operations.
  * '#include' <cstdint>: Includes the 'cstdint' header, which provides fixed-width integer types like 'size_t'.
  * '#include' <string>: Includes the 'string' header, which provides functionality for working with strings.
  * '#include' <ctime>: Includes the 'ctime' header, which provides functions for working with time and dates.

```
using namespace std;
```
- Namespace Declaration:
  *This line brings the entire std namespace into the current scope, allowing you to use standard library components without             prefixing them with std:
```
class Block                                     //
    {
        private:                                //
            size_t _nIndex;                     //Position of the block in the BlockChain

            size_t _nNonce;                     //(number used once) an arbitrary value that can be used only once in a calculation, typically a random number.Miners adjust the nonce values and compute the hash until the hash starts with a certain number of zeros.This Process Is also Known as Proof of Work
            

            time_t _CurrentTime;                //current timestamp

            string _SenderKey;                  //Public Key of the Sender
            
            string _ReceiverKey;                //Public Key of the Receiver

            int amount;                         //Amount of the Transaction

            string _sHash;                      //Hash of the Block

            string _CalculateHash() const;      //method to calculate the HAsh of the Block




        public:
            string sPrevHash;                   //Hash Of the Previous Block

            Block(size_t nIndexIn, const string &Sender, const string &Receiver, int amt);  //Constructor

            string getHash() const;
            size_t get_nIndex() const;
            string get_SenderKey() const;
            string get_ReceiverKey() const;
            int get_amount() const;
            size_t get_nNonce() const;
            time_t getCurrentTime() const;
            
            bool IsBlockValid(const Block& prevBlock) const;

            void MineBlock(size_t nDifficulty);


    };
```
- Class Declaration
  * 'class Block { ... };': This declares the 'Block' class, which encapsulates the properties and behaviors of a single block in a       blockchain.
- Private Members: These are the member variables of the 'Block' class, which are only accessible within the class itself. They        represent the characteristics of a block, such as its index, nonce value, current time, sender key, receiver key, transaction        amount, block hash, and a method to calculate the hash.
- Public Memberds: 'sPrevHash' is a public member variable that represents the hash of the previous block in the blockchain. Can       be accessed from both within or outside the class.
- Constructor: Block(size_t nIndexIn, const string &Sender, const string &Receiver, int amt):  is the constructor of the Block         class, which initializes a Block object with the provided parameters. Constructors are special member functions used to initialize   objects of a class. They have the same name as the class and are invoked automatically whenever an object of that class is created.
    
    




