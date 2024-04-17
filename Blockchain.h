#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain
    {
        private:
            size_t _nDifficulty;
            vector<Block> _vChain;

            Block _GetLastBlock() const;

        public:
            Blockchain();
            void printChain() const;
            size_t getChainSize() const;
            void AddBlock(Block bNew);


    };