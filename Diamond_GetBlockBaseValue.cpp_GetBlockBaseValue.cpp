#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h> 

static const int64_t COIN = 100000000;

static const int64 nMinSubsidy = 1 * COIN;
static const int CUTOFF_HEIGHT = 100800;	// Height at the end of 5 weeks
// miner's coin base reward based on nBits
int64 GetBlockBaseValue(int nHeight)
{
    int64 nSubsidy = COIN;

    if(totalCoin < VALUE_CHANGE)
    {
        std::string cseed_str = prevHash.ToString().substr(6,7);
        const char* cseed = cseed_str.c_str();
        long seed = hex2long(cseed);
        int rand = generateMTRandom(seed, 14400);

        // printf(">>> nHeight = %d, Rand = %d\n", nHeight, rand);
        if(rand > 10000 && rand < 10011)
        {
            nSubsidy = 30 * COIN;
        }
        else if(rand > 2000 && rand < 2031)
        {
            nSubsidy = 8 * COIN;
        }
        else if(rand > 8000 && rand < 8101)
        {
            nSubsidy = 2 * COIN;
        }
    }
    else
    {
        if(totalCoin > 1000000)
            nSubsidy = 10 * CENT;
        else if(totalCoin > 2500000)
            nSubsidy = 2 * CENT;
    }
    return nSubsidy + nFees;
}



#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
using namespace boost::python;
 
BOOST_PYTHON_MODULE(Diamond_subsidy)
{
    def("GetBlockBaseValue", GetBlockBaseValue);
}
