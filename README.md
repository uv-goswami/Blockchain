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

            string getHash() const;      // Returns Hash of the Block
            size_t get_nIndex() const;   // Returns index
            string get_SenderKey() const;   //returns public key of sender
            string get_ReceiverKey() const;  //returns public key of receiver
            int get_amount() const;      //returns the amount of the transaction
            size_t get_nNonce() const;  //returns nonce(number used once
            time_t getCurrentTime() const;     //returns the current timestamp of the block
            
            bool IsBlockValid(const Block& prevBlock) const;   //Returns true(1) or false(0)

            void MineBlock(size_t nDifficulty);


    };
```
- Class Declaration
  * 'class Block { ... };': This declares the 'Block' class, which encapsulates the properties and behaviors of a single block in a       blockchain.
- Private Members: These are the member variables of the 'Block' class, which are only accessible within the class itself. They        represent the characteristics of a block, such as its index, nonce value, current time, sender key, receiver key, transaction        amount, block hash, and a method to calculate the hash.
- Public Memberds: 'sPrevHash' is a public member variable that represents the hash of the previous block in the blockchain. Can       be accessed from both within or outside the class.
- Constructor: Block(size_t nIndexIn, const string &Sender, const string &Receiver, int amt):  is the constructor of the Block         class, which initializes a Block object with the provided parameters. Constructors are special member functions used to initialize   objects of a class. They have the same name as the class and are invoked automatically whenever an object of that class is created.

- 'time_t' is a data type represents time values. It is typically used to store time in seconds since the UNIX epoch (January 1, 1970).
- 'size_t' is a unsigned data type used for representing sizes and indices of  objects in memory. It is frequently used to represent sizes, indices, and lengths of arrays, containers, and other data structures. It ensures compatibility across different platforms and compilers, as it's guaranteed to be able to represent the size of any object in memory .
   * It is adviced not to use 'int' as 'int' may have different sizes on different compilers moreover 'int' can be both negative and positive which may allow negative values which is not feseable in context of memory sizes.
- 'void' : is used as we don't want to return the value.
- 
# Block.cpp
```
#include "Block.h"
#include <sstream>
#include <ctime> 
#include "Sha256/sha256.h"
```
-Include Derivatives:
   * '#include "Block.h"' this directive includes the header file named "Block.h" in the current source file
   * '#include <sstream>' This directive includes the standard C++ header file <sstream>, which provides            facilities for handling string streams. It is commonly used for string manipulation and stream-based          input/output operations.
   * '#include <ctime>' This directive includes the standard C++ header file <ctime>, which provides                functionality for working with date and time information. It includes declarations for various                functions and types related to time manipulation.
   * '#include "Sha256/sha256.h"' This directive includes a custom header file named "sha256.h" located in          the "Sha256" directory relative to the current source file. This header file likely contains                  declarations related to the SHA256 hashing algorithm implementation, such as function prototypes or           class definitions.

```
Block::Block(size_t nIndexin, const string &Sender, const string &Receiver, int amt) : _nIndex(nIndexin), _SenderKey(Sender), _ReceiverKey(Receiver), amount(amt)
```
   -Constructor:
   * The constructor Block::Block() initializes a Block object with specific values for its member variables.      It takes parameters nIndexin, Sender, Receiver, and amt, representing the index of the block, sender          key, receiver key, and transaction amount respectively.

```
void Block::MineBlock(size_t nDifficulty)
    {
        char cstr[nDifficulty + 1];             //Character array with size 'nDifficulty +1' to store characters for constructing strings
        for(size_t i = 0; i < nDifficulty; ++i)     //Initializes ech element of 'cstr' with character '0'
            {
                cstr[i] = '0';
            }

        cstr[nDifficulty] = '\0';       //Creates a string from the characters stored in 'cstr'

        string str(cstr);       //sets character at index 'nDifficulty' to '\0' and converts 'cstr' to string 'str' to null terminator '\0' effectively terminating the string

                std::cout << "******************************************************************************************************* "<< endl;
                std::cout << "Your Transaction is in Process......." <<endl;
        do
            {   
                _nNonce++;
                _sHash = _CalculateHash();
            }
        while(_sHash.substr(0, nDifficulty) != str);
        
    
        cout << "Current Hash: "<< _sHash << endl;
        cout << "Previous Hash: " << sPrevHash << endl;
        cout << "Sender: " <<_SenderKey << endl;
        cout << "Receiver: " <<_ReceiverKey << endl;
        cout << "Amount: " << amount << endl;
        cout << "TimeStamp: " << _CurrentTime << endl;
    }
```

- MineBlock:
   *The Block::MineBlock() method is responsible for mining a block, i.e., finding a valid hash that              satisfies a certain difficulty level. It takes a parameter nDifficulty, which determines the number of        leading zeros required in the hash.
      * It constructs a target string str with nDifficulty leading zeros
      * It repeatedly increments the nonce _nNonce and recalculates the hash _sHash until the hash meets the          difficulty target specified by str.
      * Once a valid hash is found, the method outputs information about the block including its hash, sender         and receiver keys, amount, and timestamp.

   ```
```
bool Block::IsBlockValid(const Block& prevBlock) const          
    {
        return (sPrevHash == prevBlock._sHash) && (_sHash == _CalculateHash());
    }
``` 
- IsBlockValid Method
     *The Block::IsBlockValid() method checks whether a block is valid by verifying its hash and the previous       block's hash. It takes a parameter prevBlock representing the previous block in the blockchain
     *It compares the stored previous hash sPrevHash with the hash of the previous block _sHash and checks if       the current hash _sHash matches the calculated hash using _CalculateHash()
```
string Block::_CalculateHash() const
    {
        stringstream ss;
        ss << _nIndex << _CurrentTime << _nNonce << _SenderKey << _ReceiverKey << amount;       //Concatenate  into one string

        return sha256(ss.str());        //returns SHA256 hash.
    }
```
- _CalculateHash Method:
  * The _CalculateHash() method is a private helper function used to calculate the hash of the block. It          constructs a string by concatenating various block attributes and calculates the SHA256 hash of this          string using the sha256() function.
 
# Blockchain.h
```
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain
    {
        private:
            size_t _nDifficulty;      //Represents the difficulty level of mining in the blockchain
            vector<Block> _vChain;     // Represents the chain of blocks in the blockchain.

            Block _GetLastBlock() const      //A private member function that returns the last block in the chain.

        public:
            Blockchain();
            void printChain() const;
            size_t getChainSize() const;
            void AddBlock(Block bNew);


    };
```

- Include Derivatives
  * #include <cstdint>: This directive includes the standard C++ header file <cstdint>, which provides            definitions for fixed-size integer types.
  * #include <vector>: This directive includes the standard C++ header file <vector>, which provides the 
    vector container class template for dynamic arrays.

- Public Members:
  * Blockchain(): Constructor of the Blockchain class.
  * void printChain() const;: Public member function to print the contents of the blockchain.
  * size_t getChainSize() const;: Public member function to get the size of the blockchain
  * void AddBlock(Block bNew);: Public member function to add a new block to the blockchain.

    
# Blockchain.cpp

```
Blockchain::Blockchain()
    {
        _vChain.emplace_back(Block(0, "Genesis Block", "  ", 0));       //adds a block to the chain vector 
        _nDifficulty = 5;      //Sets the difficulty level _nDifficulty to 5.
    }
```
- Constructor (Blockchain::Blockchain()):
  *Initializes a new blockchain by adding the genesis block to the chain vector _vChain.

```
void Blockchain::AddBlock(Block bNew)           
    {
        bNew.sPrevHash = _GetLastBlock().getHash();         // gets the hash of the last block in the chain
        bNew.MineBlock(_nDifficulty);    //Mines the new block with the specified difficulty level.
        _vChain.push_back(bNew);      //Pushes the new block onto the chain vector _vChain.
    }
```
- Add Block Function (Blockchain::AddBlock(Block bNew)):
  * Adds a new block bNew to the blockchain
 
# main.cpp
```
#include "Blockchain.h"
#include <iostream>
#include <string>
```
- Add the import Deravitives
```
int main() {
    Blockchain blockchain;
    }
```
- Creates an instance of the Blockchain class named blockchain.

```
blockchain.AddBlock(Block(blockchain.getChainSize(), sender, receiver, amount));
```
- this line of code creates a new block with the transaction details provided by the user and adds it to the blockchain.

  # To Compile Run
```
g++ -o blockchain Block.cpp Blockchain.cpp SHA256/sha256.cpp main.cpp
```
# To Run use:
```
./blockchain.exe
```
