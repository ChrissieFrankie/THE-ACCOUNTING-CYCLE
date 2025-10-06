#include <iostream>
#include <vector>
#include <cstdlib>

void printCycle(const std::vector<std::string> &steps, const char upto)
{
  using std::cout;
  using std::endl;
  for (size_t i = 0; i < steps.size(); i++)
  {
    if (i == upto)
    {
      break;
    }
    cout << steps[i] << endl;
  }
}

void clearTerminal() {
#ifdef _WIN32
  system("cls");  // Windows
#else
  system("clear");  // Unix/Linux/macOS
#endif
}


void promptSteps(const std::vector<std::string> &steps)
{
  using std::cin;
  using std::cout;
  using std::string;
  using std::endl;

  cout << endl << "Press ENTER to be prompted each step . . ." << endl;

  string entry;
  std::getline(std::cin, entry);

  clearTerminal();

  for (size_t i = 0; i < steps.size(); i++)
  {
    cout << i + 1 << ": ";
    string step = steps[i];
    std::getline(std::cin, entry);

    if (step == entry)
    {
      cout << "Uncle Sam is proud!\n";
    }
    else
    {
      cout << "Uncle Sam is pissed! Expected '" << step << "'\n";
      cout << "Press ENTER to not give up on Uncle Sam!" << endl;
      std::getline(cin, entry);
      clearTerminal();
      printCycle(steps, i);
      i--;
    }
  }
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
  clearTerminal();

  cout << "The Accounting Cycle (Wiley)" << endl;
  printCycle(steps, 9);
  promptSteps(steps);

  return 0;
}

/** TO DO
 * shuffle steps
 * prompt user to reorder the 9 steps
 * ^-^
 **/
