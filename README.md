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


