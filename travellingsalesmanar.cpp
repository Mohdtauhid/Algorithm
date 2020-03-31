#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void printmap(map<set<int>,int> *,int, char);
void printset(set<int>);


set<int>* getallSubsets(set<int> s, int totalelements){
    set<int> *pset = new set<int>[totalelements];
    for(int i=0; i<totalelements; i++){
        int j = 0;
        set<int> tmp = {};
        for(set<int>::iterator it = s.begin(); it != s.end(); ++it){ 
            if(i & (1 << j)){
                tmp.insert(*it); 
            }
            j++;
        } 
        pset[i] = tmp;    
    }
    //pset[0] = set<int>{};
    sort(pset, pset+totalelements,
         [](const set<int>& a, const set<int>& b)
               { return a.size() < b.size(); });
    return pset;
}




void travel(int n, int w[][4]){
    map<set<int>,int> *d = new map<set<int>,int>[n];
    map<set<int>,int> *p = new map<set<int>,int>[n];
    for(int i=1;i<n;i++){
        d[i].insert(pair<set<int>,int>(set<int>{},w[i][0]));
    }
    // v set of vertices 1 to n-1
    set<int> v = {};
    for(int i=1;i<n;i++) v.insert(i);
    int totalpsetelements = 1<<(n-1); //2**(n-1)
    // power set 
    set<int> *pset = getallSubsets(v, totalpsetelements);

    for(int iterpset = 1; iterpset<totalpsetelements; ++iterpset){
        for(int i=1;i<n;i++){
            int c = pset[iterpset].count(i);
            if(pset[iterpset].count(i) == 0){
                int j = 0,min = INT32_MAX;
                for(set<int>::iterator it = pset[iterpset].begin();it != pset[iterpset].end(); ++it){ 
                    int cost;
                    set<int> v_copy = pset[iterpset];
                    v_copy.erase(*it);
                    cost = w[i][*it] + d[*it].at(v_copy);
                    if(cost<min){
                        min = cost;
                        j = *it;
                    }
                }
                d[i].insert(pair<set<int>,int>(pset[iterpset],min));
                p[i].insert(pair<set<int>,int>(pset[iterpset],j));
            }
        }
    } 
///// for v ...ie set {1...n-1}
    int u,min = INT32_MAX;
    for(int j=1;j<n;j++){ 
        set<int> v_copy = v;
        v_copy.erase(j);
        int cost = w[0][j]+d[j].at(v_copy);
        if(cost<min){
            min = cost;
            u=j;
        }
    }
    d[0][v] = min;
    p[0][v] = u;
    cout<<"minimum cost => "<<d[0][v]<<endl;

    printmap(d,n,'D');
 
    printmap(p,n,'P');
    int x = 0;
    cout<<"\nMinimum cost route - > \n1->";
    while(!v.empty()){
        cout<<p[x][v]+1<<"->";
        x = p[x][v];
        v.erase(x);
    }
    cout<<1<<endl;

}


int main(){
    int n=4;
    int y[n][4] = {
        {0,6,1,3},
        {6,0,4,3},
        {1,4,0,2},
        {3,3,2,0}
    };
    int x[n][4] = {
        {0,3,4,3},
        {2,0,5,1},
        {3,6,0,4},
        {2,999,2,0}
    };
    int w[n][4] = {
        {0,10,15,20},
        {5,0,9,10},
        {6,13,0,12},
        {8,8,9,0}
    };
    //for(int i=0;)
    travel(n,w);
    //travel(n,x);
    //travel(n,y);



    return 0;
}

void printmap(map<set<int>,int> *d, int n,char c ){
    cout<<c<<": \n";
    for(int i=0;i<n;i++){   
        for(auto it = d[i].cbegin(); it != d[i].cend(); ++it){
            std::cout<<c<<"["<<i+1<<"]["<< "{";
            bool isphi = true;
            for (int const& setval : it->first){
                isphi = false;
                std::cout<<"V"<< setval+1 << ", ";
            }
            if(isphi) std::cout<<"  ";
            std::cout<< "\b\b}] => " << it->second<<"\n";
        }
    }
    cout<<"\n";
}

void printset(set<int> s){
    cout<<"{";
    for (int const& setval : s){
        std::cout<<"V"<< setval << ", ";
    }
    cout<<"\b\b}";
    //cout<<"\n";
}
