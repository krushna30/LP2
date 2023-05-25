#include <bits/stdc++.h>
#include <time.h>
using namespace std;

bool check(string sentence, string word)
{
    // To break the sentence in words
    stringstream s(sentence);
    // To temporarily store each individual word
    string temp;
    while (s >> temp)
    {
        // Comparing the current word
        // with the word to be searched
        if (temp.compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}

signed main()
{

    string input = "";

    map<string, vector<string>> mp;
    mp["greeting"] = {"Hello!", "Hi!", "Welcome to our online store! How can I assist you?"};

    mp["farewell"] = {"Thank you for visiting our store. Have a great day!", "Goodbye! Come back soon!"};

    mp["thanks"] = {"You're welcome!", "No problem!", "Glad to help!"};
    mp["product_inquiry"] = {"Sure, let me check that for you.", "Certainly! I'll find the information about that product."};
    mp["order_status"] = {"Please provide your order number, and I'll check its status.", "I can help you with that. What's your order number?"};
    mp["shipping_status"] = {"To track your order, please provide your order number.", "I'll assist you with the shipping status. What's your order number?"};

    mp["product_category"] = {"We offer a wide range of product categories, including shoes, shirts, and trousers.", "Our store has products in different categories such as shoes, shirts, and trousers."};

    mp["shoes_range"] = {"Sports shoes range from 900-5,000\n Sneakers range: 1,000-4,000"};

    mp["trouser_range"] = {"Chinos: 1,200-3,000\nFormals: 1,500-4,000"};

    mp["shirt_range"] = {"Formals: 2,000-5,000\nParty Wear: 1,000-4,000"};

    srand(time(NULL));

    while (true)
    {

        cout << "YOU :>";
        getline(cin, input);
        cout << "BOT :>";
        if (check(input, "goodbye") || check(input, "bye"))
        {
            int ind = rand() % (mp["farewell"].size());
            string ans = mp["farewell"][ind];
            cout << ans << endl;
            break;
        }
        else if (check(input, "hi") || check(input, "hello"))
        {
            int ind = rand() % (mp["greeting"].size());
            string ans = mp["greeting"][ind];
            cout << ans << endl;
        }

        else if (check(input, "thanks") || check(input, "thank"))
        {
            int ind = rand() % (mp["thanks"].size());
            string ans = mp["thanks"][ind];
            cout << ans << endl;
        }

        else if (check(input, "shipping") || check(input, "shipp"))
        {
            int ind = rand() % (mp["shipping_status"].size());
            string ans = mp["shipping_status"][ind];
            cout << ans << endl;
        }
        else if (check(input, "order") || check(input, "orders"))
        {
            int ind = rand() % (mp["order_status"].size());
            string ans = mp["order_status"][ind];
            cout << ans << endl;
        }
        else if (check(input, "product") || check(input, "products"))
        {
            int ind = rand() % (mp["product_category"].size());
            string ans = mp["product_category"][ind];
            cout << ans << endl;
        }
        else if (check(input, "trouser") || check(input, "trousers"))
        {
            int ind = rand() % (mp["trouser_range"].size());
            string ans = mp["trouser_range"][ind];
            cout << ans << endl;
        }
        else if (check(input, "shirt") || check(input, "shirts"))
        {
            int ind = rand() % (mp["shirt_range"].size());
            string ans = mp["shirt_range"][ind];
            cout << ans << endl;
        }

        else
        {
            cout << "Unable to get you .Please provide proper input !" << endl;
        }
    }
}