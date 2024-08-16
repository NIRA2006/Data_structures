#include <iostream>
#include <string>
using namespace std;
class Card
{
public:
    string value;
    int getRank();
};
int Card::getRank()
{
    if (value[0] >= '2' && value[0] <= '9')
    {
        return value[0] - '0';
    }
    switch (value[0])
    {
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case 'A':
        return 14;
    default:
        return -1;
    }
}
void insertionSortByRank(Card cards[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Card key = cards[i];
        int j = i - 1;
        while (j >= 0 && cards[j].getRank() > key.getRank())
        {
            cards[j + 1] = cards[j];
            j = j - 1;
        }
        cards[j + 1] = key;
    }
}
int main()
{

    int n;
    cout << "Enter the number of cards: ";
    cin >> n;
    Card cards[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of card " << i + 1 << ": ";
        cin >> cards[i].value;
    }
    insertionSortByRank(cards, n);
    cout << "\nCards sorted by rank in ascending order:\n";
    for (int i = 0; i < n; i++)
    {
        cout << cards[i].value << " ";
    }
    cout << endl;
    return 0;
}
