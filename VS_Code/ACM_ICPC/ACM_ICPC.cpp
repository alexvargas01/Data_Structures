#include <iostream>
using namespace std;

struct sTeams{
    string sName;
    int iTime = 0;
    int iAccepted = 0;
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
};

bool bCompare (sTeams t2,sTeams t1){
    return (t1.iAccepted < t2.iAccepted || (t1.iAccepted == t2.iAccepted && t1.iTime > t2.iTime));
}

int main(){
    // T = # of teams
    // P = # of problems
    // S = # of solutions sent
    int T,P,S;

    //Input of T and P
    cin>>T>>P;

    //Input of # of teams
    sTeams sTeams[T];
    for (int i=0;i<T;i++){
        cin>>sTeams[i].sName;
    }

    //Input of # of solutions sent
    cin>>S;

    string sTeamN;
    char cProblem;
    int iTimeN=0;
    char cStatus;

    for (int i=0;i<S;i++){
        cin>>sTeamN;
        cin>>cProblem;
        cin>>iTimeN;
        cin>>cStatus;

        for (int j=0;j<T;j++){
            if ( sTeamN == sTeams[j].sName){
                if (cStatus == 'A'){
                    if (sTeams[j].arr[cProblem-'A'] != 0){
                        sTeams[j].iTime += iTimeN + (20*sTeams[j].arr[cProblem-'A']);
                        sTeams[j].iAccepted ++;
                    }else{
                        sTeams[j].iTime += iTimeN;
                        sTeams[j].iAccepted ++;
                    }                    
                } else {
                    sTeams[j].arr[cProblem-'A']++;
                }
            }
        }
    }

    sort(sTeams,sTeams+T,bCompare);
    
    for (int i=0;i<T;i++){
        cout<<i+1<<" "<<"-"<<" ";
        cout<<sTeams[i].sName<<" "<<sTeams[i].iAccepted<<" ";
        if (sTeams[i].iTime == 0){
            cout<<"-"<<endl;
        }else {
            cout<<sTeams[i].iTime<<endl;
        }
    }

    return 0;
}