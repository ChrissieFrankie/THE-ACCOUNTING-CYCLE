#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

void uncleSamIsWatching(void)
{
  using std::cout;
  using std::endl;

  cout << R"(
       _..._
      |||||||
      |||||||
     _|*****|_
    ( '-...-' )
    {`;-----;`}
    {(| a  a|)}
     \|  _\ |/
      \  -  /
       '{_}`
    )" << endl;

  cout << "Uncle Sam is watching...\n";
}

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

void promptReorderSteps(const std::vector<std::string> &steps)
{
  using std::cout;
  using std::endl;
  using std::cin;

  std::vector<std::string> shuffled = steps;
  std::shuffle(shuffled.begin(), shuffled.end(), std::mt19937(std::random_device{}())); 

  bool selected = true;
  size_t selection = 0;

  while (true) {

    clearTerminal();

    cout << "Uncle Sam wants you to fix the order!" << endl; 
    cout << "Use Q to select/deselect, W/S to move up/down, and ENTER to submit!" << endl;
    cout << endl;

    if (shuffled == steps)
    {
      printCycle(shuffled, 9);
      cout << endl << "You've made Uncle Sam proud!" << endl;
      break;
    }

    for (size_t i = 0; i < shuffled.size(); i++)
    {
      cout << ((selection == i) ? (selected ? "[" : "|") : "") << shuffled[i] << ((selection == i) ? (selected ? "]" : "|") : "") << endl;
    }

    char in = ' ';
    cin >> in;

    switch (in)
    {
      case 'Q':
        selected = !selected;
        break;
      case 'S':
        selection = (selection + 1) % 9;
        if (selected)
        {
          auto oldSelection = ((selection - 1) + 9) % 9;
          std::string temp = shuffled[oldSelection];
          shuffled[oldSelection] = shuffled[selection];
          shuffled[selection] = temp; 
        }
        break;
      case 'W':
        selection = ((selection - 1) + 9) % 9;
        if (selected)
        {
          auto oldSelection = (selection + 1) % 9;
          std::string temp = shuffled[oldSelection];
          shuffled[oldSelection] = shuffled[selection];
          shuffled[selection] = temp; 
        }
        break;
      default:
        break;
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
  //  printCycle(steps, 9);
  //  promptSteps(steps);
  promptReorderSteps(steps);
  uncleSamIsWatching();

  return 0;
}

/** TO DO
 * ^-^
 **/
