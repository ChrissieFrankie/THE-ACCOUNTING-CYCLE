#include <iostream>
#include <vector>

int main(void)
{
  using std::string;
  using std::cout;
  using std::endl;
  using std::vector;

  vector<string> steps = { 
    "Analyze business transactions", 
    "Journalize the transactions",
    "Post to ledger accounts",
    "Prepare a trial balance",
    "Journalize and post adjusting entries", 
    "Prepare an adjusted trial balance", 
    "Prepare financial statements",
    "Journalize and post closing entries", 
    "Prepare a postclosing trial balance" 
  };

  cout << "The Accounting Cycle (Wiley)" << endl;

  return 0;

}

/** TO DO
 * prompt the user for the 9 steps
 * shuffle steps
 * prompt user to reorder the 9 steps
 * ^-^
 **/
