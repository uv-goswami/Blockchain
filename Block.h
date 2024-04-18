//Block.h

#include <iostream>
#include <cstdint>                              //For fixed-width integer types like 'size)_t'
#include <string>                               //For String manupaluton and storage.
#include <ctime>                                //For time related functions like getting the current time.

using namespace std;

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
            
            bool IsBlockValid(const Block& prevBlock) const;  //Validation 

            void MineBlock(size_t nDifficulty);


    };
