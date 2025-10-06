#include <iostream>
#include <vector>

void printSteps(const std::vector<std::string> &steps)
{
  using std::cout;
  using std::endl;
  for (size_t i = 0; i < steps.size(); i++)
  {
    cout << steps[i] << endl;
  }
}

void promptSteps(const std::vector<std::string> &steps)
{
  using std::cin;
  using std::cout;
  using std::string;
  string entry;

  std::getline(std::cin, entry);
  cout << entry;
}

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
  printSteps(steps);

  cout << endl << "Press ENTER to be prompted each step . . ." << endl;
  promptSteps(steps);

  return 0;

}

/** TO DO
 * prompt the user for the 9 steps
 * shuffle steps
 * prompt user to reorder the 9 steps
 * ^-^
 **/
