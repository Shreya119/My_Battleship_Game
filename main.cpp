#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
using namespace std;

int spaces = 15;
int spaces1 = 15;
int cnt5 = 5, cont5 = 5;
int cnt4 = 4, cont4 = 4;
int cnt3 = 3, cont3 = 3;
int cnt2 = 2, cont2 = 2;
int cnt1 = 1, cont1 = 1;
vector<vector<char>> m1(10, vector<char>(10, '.'));
vector<vector<char>> m2(10, vector<char>(10, '.'));

// computer side-
vector<vector<char>> m3(10, vector<char>(10, '.'));

vector<char> v={'A','B','C','D','E','F','G','H','I','J'};

int chartointeger(char c){
  for(int i=0;i<10;i++){
    if(v[i]==c){
      return i;
    }
  }
  return -1;
}

int random(int low, int high)
{
    int r = rand();
    return low + r % (high);
}

void showgrid(vector<vector<char>> &m)
{

    cout << "   A|B|C|D|E|F|G|H|I|J"
         << "\n\n";
    for (int i = 0; i < 10; i++) // column loop
    {
        for (int j = 0; j < 10; j++) // row loop
        {
            if (j == 0)
            {
                cout << i << "  "; // print row number and spaces before new row
            }
            cout << m[i][j];
            if (j != 9)
            {
                cout << "|";
            }
        }
        cout << "\n"; // new line at end of column
    }
    cout << "\n";
}

// checks the coordinates-
bool check(int x, int y, vector<vector<char>> &m)
{
    if (x >= 10 || x < 0 || y >= 10 || y < 0 || m[x][y] != '.')
    {
        return false;
    }
    return true;
}

bool check1(int x, int y, vector<vector<char>> &m)
{
    if (x >= 10 || x < 0 || y >= 10 || y < 0)
    {
        return false;
    }
    return true;
}

// choosing random positions for computer-
void choosepos1(int pos, char c, vector<vector<char>> &m1)
{
    int x, y;
    x = random(0, 9);
    y = random(0, 9);
    int n = random(1, 2);
    int poss = pos;
    if (n == 1)
    {
        while (poss--)
        {
            if (check(x, y, m1))
            {
                m1[x][y] = c;
                x++;
            }
            else
            {
                poss = pos - poss - 1;
                while (poss--)
                {
                    x--;
                    m1[x][y] = '.';
                }
                choosepos1(pos, c, m1);
                break;
            }
        }
    }
    else
    {
        while (poss--)
        {
            if (check(x, y, m1))
            {
                m1[x][y] = c;
                y++;
            }
            else
            {
                poss = pos - poss - 1;
                while (poss--)
                {
                    y--;
                    m1[x][y] = '.';
                }
                choosepos1(pos, c, m1);
                break;
            }
        }
    }
}

// chooses position of ship-
void choosepos(int pos, char c, vector<vector<char>> &m1)
{
    int x;
    cout << "Enter the starting coordinates of ship-"
         << "\n\n";
     char p;
    cin >> x >> p;
    int y=chartointeger(p);
    cout << "Orientation of ship- 1 Vertical, 2 Horizontal"
         << "\n\n";
    int n;
    cin >> n;
    int poss = pos;
    if (n == 1)
    {
        while (poss--)
        {
            if (check(x, y, m1))
            {
                m1[x][y] = c;
                x++;
            }
            else
            {
                poss = pos - poss - 1;
                while (poss--)
                {
                    x--;
                    m1[x][y] = '.';
                }
                cout << "Enter the valid coordinates"
                     << "\n\n";
                choosepos(pos, c, m1);
                break;
            }
        }
    }
    else
    {
        while (poss--)
        {
            if (check(x, y, m1))
            {
                m1[x][y] = c;
                y++;
            }
            else
            {
                poss = pos - poss - 1;
                while (poss--)
                {
                    y--;
                    m1[x][y] = '.';
                }
                cout << "Enter the valid coordinates"
                     << "\n\n";
                choosepos(pos, c, m1);
                break;
            }
        }
    }
}

// Attack algo by computer-
void Attack1()
{
    int x, y;
    x = random(0, 9);
    y = random(0, 9);

    if (check1(x, y, m1))
    {
        if (m1[x][y] != '.')
        {
            spaces1--;
            cout << "It's a Hit by CPU"
                 << "\n\n";

            if (m1[x][y] == 'A')
            {
                m1[x][y] = '@';
                cont5--;
                if (cont5 == 0)
                {
                    cout << "Your Aircraft carrier got sunk"
                         << "\n\n";
                }
            }
            else if (m1[x][y] == 'B')
            {
                m1[x][y] = '@';
                cont4--;
                if (cont4 == 0)
                {
                    cout << "Your Battleship got sunk"
                         << "\n\n";
                }
            }
            else if (m1[x][y] == 'C')
            {
                m1[x][y] = '@';
                cont3--;
                if (cont3 == 0)
                {
                    cout << "Your Destroyer got sunk"
                         << "\n\n";
                }
            }
            else if (m1[x][y] == 'D')
            {
                m1[x][y] = '@';
                cont2--;
                if (cont2 == 0)
                {
                    cout << "Your Corvette got sunk"
                         << "\n\n";
                }
            }
            else if (m1[x][y] == 'E')
            {
                m1[x][y] = '@';
                cont1--;
                if (cont1 == 0)
                {
                    cout << "Your Frigate got sunk"
                         << "\n\n";
                }
            }
        }
        else
        {
            cout << "It's a Miss by CPU"
                 << "\n\n";
        }
    }
    else
    {
        Attack1();
    }
}

void Attack()
{
    int x;
    char p;
    cin >> x >> p;
    int y=chartointeger(p);
    if (check1(x, y, m3))
    {
        if (m3[x][y] != '.')
        {
            spaces--;
            cout << "It's a Hit"
                 << "\n\n";

            if (m3[x][y] == 'A')
            {
                m2[x][y] = 'H';
                cnt5--;
                if (cnt5 == 0)
                {
                    cout << "Aircraft carrier got sunk"
                         << "\n\n";
                }
            }
            else if (m3[x][y] == 'B')
            {
                m2[x][y] = 'H';
                cnt4--;
                if (cnt4 == 0)
                {
                    cout << "Battleship got sunk"
                         << "\n\n";
                }
            }
            else if (m3[x][y] == 'C')
            {
                m2[x][y] = 'H';
                cnt3--;
                if (cnt3 == 0)
                {
                    cout << "Destroyer got sunk"
                         << "\n\n";
                }
            }
            else if (m3[x][y] == 'D')
            {
                m2[x][y] = 'H';
                cnt2--;
                if (cnt2 == 0)
                {
                    cout << "Corvette got sunk"
                         << "\n\n";
                }
            }
            else if (m3[x][y] == 'E')
            {
                m2[x][y] = 'H';
                cnt1--;
                if (cnt1 == 0)
                {
                    cout << "Frigate got sunk"
                         << "\n\n";
                }
            }
        }
        else
        {
            cout << "It's a Miss"
                 << "\n\n";
            m2[x][y] = '*';
        }
    }
    else
    {
        cout << "Enter valid coordinates"
             << "\n";
        Attack();
    }
}

int main()
{
    srand(time(0));
    // choosing positions of boats for computer;
    choosepos1(5, 'A', m3);
    choosepos1(4, 'B', m3);
    choosepos1(3, 'C', m3);
    choosepos1(2, 'D', m3);
    choosepos1(1, 'E', m3);
    cout << "Welcome to the Battleship Game"
         << "\n\n";
    cout << "\t\t Ship Grid"
         << "\n\n";
    showgrid(m1);
    cout << "\t\t Attack Grid"
         << "\n\n";
    showgrid(m2);
    cout << "Type of ships -"
            "\n"
            "1. Aircraft carrier (occupies 5 spaces)"
            "\n"
            "2. Battleship (4 spaces)"
            "\n"
            "3. Destroyer (3 spaces)"
            "\n"
            "4. Corvette (2 spaces) "
            "\n"
            "5. Frigate (1 space)"
         << "\n \n";
    cout << "Choose position for Aircraft carrier (occupies 5 spaces)"
         << "\n\n";
  cout<<"Example of a valid position- 6 A"<<"\n \n";
    choosepos(5, 'A', m1);
    showgrid(m1);
    cout << "Choose position for Battleship (occupies 4 spaces)"
         << "\n\n";
    choosepos(4, 'B', m1);
    showgrid(m1);
    cout << "Choose position for  Destroyer (occupies 3 spaces)"
         << "\n\n";
    choosepos(3, 'C', m1);
    showgrid(m1);
    cout << "Choose position for Corvette  (occupies 2 spaces)"
         << "\n\n";
    choosepos(2, 'D', m1);
    showgrid(m1);
    cout << "Choose position for Frigate (occupies 1 spaces)"
         << "\n\n";
    choosepos(1, 'E', m1);
    cout << "          Ship Grid"
         << "\n\n";
    showgrid(m1);
    cout << "          Attack Grid"
         << "\n\n";
    showgrid(m2);
    cout << "Game Starts...."
         << "\n\n";
    bool endgame = false;

    while (!endgame)
    {
        cout << "Enter Attack Coordinates-"
             << "\n\n";
        Attack();
        sleep(2);
        cout << "          Ship Grid"
             << "\n\n";
        showgrid(m1);
        cout << "          Attack Grid"
             << "\n\n";
        showgrid(m2);
        if (!spaces)
        {
            cout << "You Won the Game !!"
                 << "\n\n";
            endgame = true;
        }
        Attack1();
        sleep(2);
        cout << "          Ship Grid"
             << "\n\n";
        showgrid(m1);
        cout << "          Attack Grid"
             << "\n\n";
        showgrid(m2);
        if (!spaces1)
        {
            cout << "CPU Won the Game !!"
                 << "\n\n";
            endgame = true;
        }
    }

    cout << "Game Ended";

    return 0;
}
