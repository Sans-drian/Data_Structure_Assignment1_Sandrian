#include <iostream>

using namespace std;


class Laptop {
  public:
    string brand;
    string  model;
    int stock;
    Laptop(string brd,string mdl,int stck){
        brand = brd;
        model = mdl;
        stock =stck;
    };
    string display(){
        return brand +" - "+ model +" - "+ to_string(stock)+"\n";
    }
};

class Store {
  public:
    string name;
    int length = 0;
    int max = 3;
    Laptop *list= (Laptop*)malloc(sizeof(Laptop) * max);
    void addLaptop(Laptop& item);
    void addStock(string brand,string model,int stock);
    void display();
    void sell(string brand,string model,int sell);
    void search(Laptop);

};

void Store::addLaptop(Laptop& item){
    if(length < max){
        list[length] = item;
        length++;
        cout<<"laptop added "+to_string(length)+"\n";
    }else{
        cout<<"array full \n";
    }
}

void Store::display(){
    for(int i =0;i<length;i++){
        cout<<list[i].display();
    }
}

void Store::addStock(string brand,string model,int stock){
    bool found = false;
    for(int i =0;i<length;i++){
        if(list[i].brand.compare(brand)==0 && list[i].model.compare(model)==0){
            list[i].stock = list[i].stock + stock;
            found = true;
            cout<<"stock updated \n";
            break;
        }
    }
    if(!found){
        cout<<"laptop not found \n";
    }
}

void Store::sell(string brand,string model,int sell){
    bool found = false;
    for(int i =0;i<length;i++){
        if(list[i].brand.compare(brand)==0 && list[i].model.compare(model)==0){
            found = true;
            if(sell>list[i].stock){
                cout<<"item not enough \n";
            }else{
                list[i].stock = list[i].stock - sell;
                cout<<"item sold \n";
            }
            break;
        }
    }
    if(!found){
        cout<<"laptop not found \n";
    }
}




int main()
{
    string strbrand,strmodel;
    int it,howMany;
    Store store;
    Laptop l = Laptop("Acer","Aspire",3);
    store.addLaptop(l);
    l= Laptop("Asus","Zenbook",3);
    store.addLaptop(l);

    while(it != 4){
        cout<<"please select number (1)Display item (2)Add Item (3)Sell item (4)Exit \n";
        cin>>it;
        if(it==1){
            cout<<"you choose 1.Display Item \n";
            store.display();
        }else if(it==2){
            cout<<"you choose 2.Add Item \n";
            cout<<"type brand : ";
            cin>>strbrand;
            cout<<"type model : ";
            cin>>strmodel;
            cout<<"how many laptop to add : ";
            cin>>howMany;
            store.addStock(strbrand,strmodel,howMany);
        }else if(it==3){
            cout<<"you choose 3.Sell Item \n";
            cout<<"type brand : ";
            cin>>strbrand;
            cout<<"type model : ";
            cin>>strmodel;
            cout<<"how many laptop to sell : ";
            cin>>howMany;
            store.sell(strbrand,strmodel,howMany);
        }else{
            cout<<"wrong number, try again \n";
        }
    }

    return 0;
}
