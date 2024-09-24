#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void getDataFromFile(vector<string> &investor, vector<string> &investmentNames, vector<double> &investmentPrices, vector<double> &shares){
    ifstream inFile;
    inFile.open("InvestmentData.txt");
    string investorName;
    string name;
    double price;
    double sharesAmt;
    while(inFile >> investorName >> name >> price >> sharesAmt){
      investor.push_back(investorName);
        investmentNames.push_back(name);
        investmentPrices.push_back(price);
        shares.push_back(sharesAmt);
    }
      
        
    }

void displayData(vector<string> &investor, vector<string> &investmentNames, vector<double> &investmentPrices, vector<double> &shares){
  for(int i=0; i<investor.size(); i++){
      cout << investor[i] << ": " << investmentNames[i] << " " << investmentPrices[i] << " " <<  shares[i] << endl;
  }
}

void addDataToFile(string investorName, string investmentName, double investmentPrice, double shares){
    ofstream outFile;
    outFile.open("InvestmentData.txt", ios::app);
  bool continueLoop = true;
   investorName = "";
  investmentName = "";
  investmentPrice = 0;
  shares = 0;
  while(continueLoop == true){
    cout << endl;
    cout << "Would you like to add an investment? (y/n): ";
    string choice;
    cin >> choice;
    cin.ignore();
   if (choice == "n" || choice == "N" || choice == "no" || choice == "No"){
     continueLoop = false;
   }
     else  {
      cout << "Enter Investor Name: ";
       getline(cin, investorName);
       outFile << investorName << " ";
      cout << "Enter Investment Name: ";
       getline(cin, investmentName);
       outFile << investmentName << " ";
      cout << "Enter Investment Price: ";
       cin >> investmentPrice;
       outFile << investmentPrice << " ";
      cout << "Enter Number of Shares: ";
       cin >> shares;
       outFile << shares << endl;
       cin.ignore();
     
     }

   }
   }

void calculateTotals(vector<string> &investor, vector<string> &investmentNames, vector<double> &investmentPrices, vector<double> &shares){
  ofstream outFileTotal;
  outFileTotal.open("InvestmentTotals.txt");
  double bitcoinPrice = 0;
  double solanaPrice = 0;
  
  double btcTotal1 = 0;
  double btcTotal2= 0;
  double btcCurrentAmt1 = 0;

  double btcSharesTotal1 = 0;
  double btcSharesTotal2 = 0;
  double btcCurrentAmt2 = 0;

  double usdcTotal1 = 0;
  double usdcTotal2 = 0;

  double solTotal1 = 0;
  double solTotal2 = 0;

  double solSharesTotal1 = 0;
  double solSharesTotal2 = 0;

  double solCurrentAmt1 = 0;
  double solCurrentAmt2 = 0;
  
  double elanaTotal = 0;
  double michaelTotal = 0;
  double ourTotal = 0;

cout << "What is the current price of Bitcoin?: ";
cin >> bitcoinPrice;
cin.ignore();
cout << endl;
cout << "What is the current price of Solana?: ";
cin >> solanaPrice;
cin.ignore();


  
  
  for(int i=0; i < investmentNames.size(); i++){
    if(investor[i] == "Elana" || investor[i] == "elana" || investor[i] == "Elasha" || investor[i] == "elasha" || investor[i] == "elash" || investor[i] == "Elash"){
      if(investmentNames[i] == "Bitcoin" || investmentNames[i] == "bitcoin" || investmentNames[i] == "Btc" || investmentNames[i] == "BTC" || investmentNames[i] == "btc"){
      btcTotal1 += investmentPrices[i];
      btcSharesTotal1 += shares[i];
       }
     }
  }
  
  for(int i=0; i < investmentNames.size(); i++){
    if(investor[i] == "Elana" || investor[i] == "elana" || investor[i] == "Elasha" || investor[i] == "elasha" || investor[i] == "elash" || investor[i] == "Elash"){
      if(investmentNames[i] == "USDC" || investmentNames[i] == "usdc" || investmentNames[i] == "Usdc"){
        usdcTotal1 += investmentPrices[i];
      }
    }
  }

for(int i=0; i<investmentNames.size(); i++){
  if (investor[i] == "Michael" || investor[i] == "michael"){
    if(investmentNames[i] == "Bitcoin" || investmentNames[i] == "bitcoin" || investmentNames[i] == "Btc" || investmentNames[i] == "BTC" || investmentNames[i] == "btc"){
      btcTotal2 += investmentPrices[i];
      btcSharesTotal2 += shares[i];   
    }
  }
}

for(int i=0; i<investmentNames.size(); i++){
  if (investor[i] == "Michael" || investor[i] == "michael"){
    if(investmentNames[i] == "USDC" || investmentNames[i] == "usdc" || investmentNames[i] == "Usdc"){
      usdcTotal2 += investmentPrices[i];
    }
  }
}

for(int i=0; i < investmentNames.size(); i++){
  if(investor[i] == "Elana" || investor[i] == "elana" || investor[i] == "Elasha" || investor[i] == "elasha" || investor[i] == "elash" || investor[i] == "Elash"){
    if(investmentNames[i] == "Solana" || investmentNames[i] == "solana" || investmentNames[i] == "Sol" || investmentNames[i] == "sol" || investmentNames[i] == "SOL"){
      solTotal1 += investmentPrices[i];
      solSharesTotal1 += shares[i];
    }
  }
}

  for(int i=0; i < investmentNames.size(); i++){
    if(investor[i] == "Michael" || investor[i] == "michael"){
      if(investmentNames[i] == "Solana" || investmentNames[i] == "solana" || investmentNames[i] == "Sol" || investmentNames[i] == "sol" || investmentNames[i] == "SOL"){
        solTotal2 += investmentPrices[i];
        solSharesTotal2 += shares[i];
      }
    }
  }

double btcProfit1 = 0.0;
double btcProfit2 = 0.0;

double solProfit1 = 0;
double solProfit2 = 0;
  
solCurrentAmt1 = solanaPrice * solSharesTotal1;
solCurrentAmt2 = solanaPrice * solSharesTotal2;

solProfit1 = solCurrentAmt1 - solTotal1;
solProfit2 = solCurrentAmt2 - solTotal2;
    
btcCurrentAmt1 = btcSharesTotal1 * bitcoinPrice;
btcCurrentAmt2 = btcSharesTotal2 * bitcoinPrice;

btcProfit1 = btcCurrentAmt1 - btcTotal1;
btcProfit2 = btcCurrentAmt2 - btcTotal2;

elanaTotal = btcCurrentAmt1 + usdcTotal1 + solCurrentAmt1;
michaelTotal = btcCurrentAmt2 + usdcTotal2 + solCurrentAmt2;
ourTotal = elanaTotal + michaelTotal;

  //In the future change this to only print if totals are more than 0$
  
outFileTotal << "____________________________________" << endl;
outFileTotal << "| Elana's Totals: $"  << left << setfill(' ') << setw(16) << elanaTotal << "|"<< endl;
  if (btcTotal1 > 0){
outFileTotal << "| BTC Bought: $" << left << setfill(' ') << setw(20) << btcTotal1  << "|" <<endl;
outFileTotal << "| BTC Shares Owned: "  << left << setfill(' ') << setw(15) << btcSharesTotal1  << "|" << endl;
outFileTotal << "| BTC Current Value: $" << left << setfill(' ') << setw(13) << btcCurrentAmt1  << "|" << endl;
outFileTotal << "| BTC Profit: $" << left << setfill(' ') << setw(20) << btcProfit1  << "|" <<endl;
  }
  if (usdcTotal1 > 0){
outFileTotal << "| USDC: $" << left << setfill(' ') << setw(26) << usdcTotal1 << "|" << endl;
  }
  if(solTotal1 > 0){
outFileTotal << "| SOL Bought: $" << left << setfill(' ') << setw(20) << solTotal1 << "|" << endl;
outFileTotal << "| SOL Shares Owned: " << left << setfill(' ') << setw(15) << solSharesTotal1 << "|" << endl;
outFileTotal << "| SOL Current Value: $" << left << setfill(' ') << setw(13) << solCurrentAmt1 << "|" << endl;
outFileTotal << "| SOL Profit: $" << left << setfill(' ') << setw(20) << solProfit1 << "|" << endl;
  }
outFileTotal << "|__________________________________|" << endl;
outFileTotal << endl;
outFileTotal << "____________________________________" << endl;
outFileTotal << "| Michael's Totals: $" << left << setfill(' ') << setw(14) << michaelTotal << "|" << endl; 
  if (btcTotal2 > 0){
outFileTotal << "| BTC Bought: $" << left << setfill(' ') << setw(20) << btcTotal2 << "|" << endl;
outFileTotal << "| BTC Shares Owned: " << left << setfill(' ') << setw(15) << btcSharesTotal2 << "|" << endl;
outFileTotal << "| BTC Current Value: $" << left << setfill(' ') << setw(13) << btcCurrentAmt2 << "|" << endl;
outFileTotal << "| BTC Profit: $" << left << setfill(' ') << setw(20) << btcProfit2  << "|" <<endl;
  }
  if (usdcTotal2 > 0){
outFileTotal << "| USDC: $" << left << setfill(' ') << setw(26) << usdcTotal2 << "|" << endl;
  }
  if (solTotal2 > 0){
outFileTotal << "| SOL Bought: $" << left << setfill(' ') << setw(20) << solTotal2 << "|" << endl;
outFileTotal << "| SOL Shares Owned: " << left << setfill(' ') << setw(15) << solSharesTotal2 << "|" << endl;
outFileTotal << "| SOL Current Value: $" << left << setfill(' ') << setw(13) << solCurrentAmt2 << "|" << endl;
outFileTotal << "| SOL Profit: $" << left << setfill(' ') << setw(20) << solProfit2 << "|" << endl;
  }
outFileTotal << "|__________________________________|" << endl;
outFileTotal << endl;
outFileTotal << endl;

string ourTotalString = to_string(ourTotal);
string ourTotalString2 = ourTotalString.substr(0, ourTotalString.find(".") + 3);
string ourTotalString3 = ourTotalString2 + " |";

string ourTotalProfit = to_string(btcProfit1 + btcProfit2 + solProfit1 + solProfit2);
string ourTotalProfit2 = ourTotalProfit.substr(0, ourTotalProfit.find(".") + 3);
string ourTotalProfit3 = ourTotalProfit2 + " |";

  
outFileTotal << "           dddddddd                  ddddddddd      " << endl;
outFileTotal << "         dddddddddddd              ddddddddddddd    " << endl;
outFileTotal << "       ddddddddddddddd           ddddddddddddddddd   " << endl;
outFileTotal << "      dddddddddddddddddd       dddddddddddddddddddd " << endl;
outFileTotal << "     dddddddddddddddddddd    ddddddddddddddddddddddd " << endl;
outFileTotal << "    dddddddddddddddddddddd  dddddddddddddddddddddddd " << endl;
outFileTotal << "    dddddddddddddddddddddddddddddddddddddddddddddddd " << endl;
outFileTotal << "    dddddd| Elasha & Mishka Total: $" << left << setfill('d') << setw(16) << ourTotalString3 << endl;
outFileTotal << "      ddddddddd| Total Profit: $" << left << setfill('d') << setw(18) << ourTotalProfit3 << endl;  
outFileTotal << "        dddddddddddddddddddddddddddddddddddddddd     " << endl;
outFileTotal << "          dddddddddddddddddddddddddddddddddddd       " << endl;
outFileTotal << "            dddddddddddddddddddddddddddddddd        " << endl;
outFileTotal << "              dddddddddddddddddddddddddddd           " << endl;
outFileTotal << "                dddddddddddddddddddddddd             " << endl;
outFileTotal << "                  dddddddddddddddddddd               " << endl;   
outFileTotal << "                    dddddddddddddddd                 " << endl;
outFileTotal << "                      dddddddddddd                   " << endl;
outFileTotal << "                        dddddddd                     " << endl;
outFileTotal << "                          dddd                      " << endl;
  
//outFileTotal << "             Elasha & Mishka Total: $" << ourTotal << endl;
}
//convert double to string
 

int main(){
vector<string> investor;
vector<string> investmentNames;
vector<double> investmentPrices;
vector<double> shares;

  string investorName = "";
  string investmentName = "";
  double investmentPrice = 0;
  double numOfShares = 0;
  
getDataFromFile(investor, investmentNames, investmentPrices, shares);
displayData(investor, investmentNames, investmentPrices, shares);
addDataToFile(investorName, investmentName, investmentPrice, numOfShares);


  cout << "Would you like to calculate totals? (y/n): ";
  string choice;
  cin >> choice;
  cin.ignore();
  if (choice == "n" || choice == "N" || choice == "no" || choice == "No"){
    cout << "Thank You!" << endl;
    return 0;
    }
    else {
      calculateTotals(investor, investmentNames, investmentPrices, shares);
    }
  
  return 0;
}