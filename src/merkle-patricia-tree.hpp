#pragma once
#include <string>
#include <vector>
#include "sha.hpp"
using namespace std;

using std::byte = uint8_t;
using vector_ref<std::byte> = vector<std::byte>;
using vector_ref<std::byte const> = vector<std::byte const>;

class MPTNode
{
public:
    std::string const &at(vector_ref<std::byte const> _key) const;
    virtual MPTNode *insert(vector_ref<std::byte const> _key, std::string const &_value);
    virtual MPTNode *remove(vector_ref<std::byte const> _key);
    void putRLP(RLPStream &_parentStream) const;

    /// 256-bit hash of the node - this is a SHA-3/256 hash of the RLP of the node.
    string hash256() const
    {
        RLPStream s;
        makeRLP(s);
        return hash_sha256(s.out());
    }
    vector_ref<std::byte> rlp() const
    {
        RLPStream s;
        makeRLP(s);
        return s.out();
    }
    // void mark() { hash = hash_sha256(); }

private:
    string hash;
};

class MerklePatriciaTree
{
private:
    MPTNode *root;

public:
};