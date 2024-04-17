#include "Block.h"
#include <sstream>
#include <ctime> 
#include "Sha256/sha256.h"

using namespace std;
//Class constructor                                                                     Initializer list where member variables of the 'Block' class are initialized
Block::Block(size_t nIndexin, const string &Sender, const string &Receiver, int amt) : _nIndex(nIndexin), _SenderKey(Sender), _ReceiverKey(Receiver), amount(amt)
    {
        _nNonce = -1;
        _CurrentTime = time(nullptr);
    }

string Block::getHash() const      // It retrieves and returns the hash of the block without modifying it 
{
    return _sHash;
}

int Block::get_amount()  const
{
    return amount;
}

size_t Block:: get_nNonce() const
    {
        return _nNonce;
    }

string Block::get_ReceiverKey() const
    {
        return _ReceiverKey;
    }

string Block::get_SenderKey() const
    {
        return _SenderKey;
    }

time_t Block::getCurrentTime() const
    {
        return _CurrentTime;
    }

size_t Block::get_nIndex() const
    {
        return _nIndex;
    }




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

inline string Block::_CalculateHash() const
    {
        stringstream ss;
        ss << _nIndex << _CurrentTime << _nNonce << _SenderKey << _ReceiverKey << amount;

        return sha256(ss.str());
    }