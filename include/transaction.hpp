#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <openssl/sha.h>
#include <openssl/dsa.h>
#include <openssl/engine.h>

/*The smallest FunCoin unit*/
using Fundoshi = unsigned long;

class Transaction 
{
 public:
  Transaction(Fundoshi amount, Transaction* input, std::string signature);

  /**
   * Adds an input to this transaction.
   * @param amount, the amount in fundoshi to add to this
   * transaction.
   * @param input, the input transaction
   */
  void addInput(Fundoshi amount, Transaction* input);

  /**
   * Adds an output transaction and a change transaction
   * to this transaction. If there is no change for this
   * transaction, set change to NULL.
   *
   * @param output, the output transaction
   * @param change, the change transaction
   */
  void addOutput(Transaction* output, Transaction* change);

  /**
   * Returns the unspent funcoin. If the ouput
   * is not null, returns 0
   * @return unspent function if output = null, 0 otherwise
   */
  Fundoshi getUnspent();

  /**
   * Returns the signature of this transaction.
   * @return the signature
   */
  std::string getSignature();

  /**
   * Returns all the inputs of this transaction
   * @return the inputs
   */
  std::vector<Transaction*> getInputs();
  
  friend std::ostream &operator<<(std::ostream &output, const Transaction &T) {
    output << T.signature << " $" <<  T.amount << std::endl;
    return output;
  }


  Fundoshi amount;
  std::string signature;
  std::vector<Transaction*> input;
  Transaction* output;
  Transaction* change;
};


