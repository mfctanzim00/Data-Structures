#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;
const ll mx = 1e9+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

struct node
{
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
}*root;

void insert(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(char* str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur)
{
    for (int i=0; i<26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i=1; i<=num_word; i++)
    {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    puts("ENTER NUMBER OF QUERY: " );
    int query;
    cin >> query;
    for (int i=1; i<=query; i++)
    {
        char str[50];
        scanf("%s", str);
        if (search(str, strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root);
    return 0;
}

