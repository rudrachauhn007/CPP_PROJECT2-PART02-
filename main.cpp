// shree ganeshaya namaha:|
// shree chamudamataya namaha:|
// shree saraswatimataya namaha:|
#include <bits/stdc++.h>
using namespace std;
class bill
{
    string item;
    double rate;
    int quantity;

public:
    bill() 
    {
    item = "";
    rate = 0.00;
    quantity = 0;
    }
    void set_item(string name)
    {
        item=name;
    }
   void  set_rate (double rat)
    {
        rate = rat;
    }
    void set_quantity(int quan)
    {
        quantity = quan;
    }
    string get_item()
    {
        return item;
    }
    double get_rate()
    {
        return rate;
    }
    int get_quantity()
    {
        return quantity;
    }

};

void additem(bill b)
{
    bool close=false;
    while (!close)
    {
        int choice;
        cout << "\t\t1.add" << endl;
        cout << "\t\t2.close" << endl;
        cout << "\t\tENTER CHOICE :";
        cin >> choice;
        if (choice == 1)
        {
            string item1;
            double rate1;
            int quantity1;
            cout << "\t\tENTER THE ITEM NAME :";
            cin >> item1;
            cout << "\t\tENTER THE RATE :";
            cin >> rate1;
            cout << "\t\tENTER THE QUANTITY :";
            cin >> quantity1;
            b.set_item(item1);
            b.set_quantity(quantity1);
            b.set_rate(rate1);
            ofstream outfile("output.txt",ios::app);// apending mode
            if (!outfile)
            cout << "FILE NOT OPENED PROPERLY" << endl;
            else
            {
                outfile << "\t" << b.get_item() << " : " << b.get_rate() << " : " << b.get_quantity() << endl << endl;; 
            }
            outfile.close ();
            cout << "\t\titem added successfully" << endl;
        }
        else if (choice == 2)
        {
          close = true;
          cout << "\t\tBACK TO MAIN MENU" << endl;
        }
    }
}
void printbill()
{
    int count=0;
    bool close=false;
    while (!close)
    {
        int choice;
        cout << "\t1.Add Bill." << endl;
        cout << "\t2.Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("output.txt");
            ofstream out("Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line))
            {
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
                    }
                    else
                    {
                        cout << "\tSorry, " << item << " Ended!" << endl;
                    }
                }
                else
                {
                    out << line << endl;
                }
            }
            if (!found)
            {
                cout << "\tItem Not Available!" << endl;
            }
            out.close();
            in.close();
            remove("output.txt");
            rename("Temp.txt", "output.txt");
        }
        else if (choice == 2)
        {
            close = true;
            cout << "\t\t COUNTING TOTAL BILL" << endl;
        }
    }
    cout << endl << endl;
    string name,ph_number;
    cout << "ENTER THE NAME AND MOBILE NUMBER :";
    cin >> name >> ph_number;
    cout << "\t TOTAL BILL -----------------------------------------" << count << endl << endl;
    ifstream input("billno.txt");
    int num;
    input >> num;
    string s= "bill"+ to_string(( ++num))+ ".txt";
    ofstream output (s);
    output << count << endl;
    output << name << endl;
    output << ph_number << endl;
    input.close();
    output.close();
    ofstream in("billno.txt");
    in<<num << endl;

    cout << "\t\t THANKS FOR SHOPING" << endl;
}
int main ()
{
    bill b;
    bool exit = false;
    while (!exit)
    {
      int val;
      cout << "\t WELCOME TO THE INVENTORY MANAGEMENT SYSTEM"<< endl;
      cout << "\t*******************************************"<<endl;
      cout << "\t\t 1.ADD ITEMS" << endl;
      cout << "\t\t 2.Print Bill" << endl;
      cout << "\t\t 3.Exit " << endl;
      cout << "\t\tEnter Choice" ;
      cin >> val;
      if (val==1)
      {
        // user want to add items
        additem(b);
      }
      else if (val==2)
    {
        // user want to purchase items
        printbill();
    }
    else if (val==3)
    {
        exit=true;
        cout << "\t GOOD luck" << endl;
    }
    }
}