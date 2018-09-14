//define the max size of the hashtable
const byte HASH_SIZE = 68;
//storage
HashType<int,int> hashRawArray[HASH_SIZE];
//handles the storage [search,retrieve,insert]
HashMap<int,int> hashMap = HashMap<int,int>( hashRawArray , HASH_SIZE );

