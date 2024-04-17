#include "Blockchain.h"


Blockchain::Blockchain()
    {
        _vChain.emplace_back(Block(0, "Genesis Block", "  ", 0));       //adds a block to the chain vector 
        _nDifficulty = 5;
    }

void Blockchain::AddBlock(Block bNew)           
    {
        bNew.sPrevHash = _GetLastBlock().getHash();         // gets the hash of the last block in the chain
        bNew.MineBlock(_nDifficulty);
        _vChain.push_back(bNew);
    }

Block Blockchain:: _GetLastBlock() const
    {
        return _vChain.back();
    }

void Blockchain::printChain() const
    {
        for(size_t i =1; i<_vChain.size(); ++i)
            {
                const Block& block = _vChain[i];    //creates a constant reference to the block in the chain vector 
                std::cout<< "************************************************************************************************"<< std::endl;
                std::cout<< "Block: "<< block.get_nIndex()<< std::endl;
                std::cout<< "Block Hash: " << block.getHash() << std::endl;
                std::cout<< "Previous Hash: " << block.sPrevHash << std::endl;
                std::cout<< "Sender: " << block.get_SenderKey()<<std::endl;
                std::cout<< "Receiver: " << block.get_ReceiverKey()<<std::endl;
                std::cout<< "Amount: " << block.get_amount()<<std::endl;
                std::cout<< "Nonce: " << block.get_nNonce()<<std::endl;
                std::cout<< "Timestamp: "<< block.getCurrentTime()<< std::endl;
            }

    }


size_t Blockchain::getChainSize() const
    {
        return _vChain.size();
    }