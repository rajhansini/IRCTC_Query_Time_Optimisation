// code for the lab 9 
// hashing 

#include<iostream>
using namespace std;
#include<cstdlib>
#include<string>
#include<fstream>
#include<sstream>
#include<time.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

 
// self referential structure
struct node
{

	string nm,stnm;
        string no,seq,dist; 
        string arr,dept,val,sourcestanm,deststa,deststanm,code;
        node *next;  


}*t,*top[26],*ptr,*tmp;// end of structure


// creation of the linklist
void createnewnode()
{
 
        string a;
	t=new node;
        cout<<"\n train no. ";
        cin>>a;
        t->no=a;
        cout<<"\n train name";
        cin>>a;
        t->nm=a;
        cout<<"\n seq ";
        cin>>a;
        t->seq=a;
        cout<<"\n station code ";
        cin>>a;
        t->val=a;  
        t->code=a;
        cout<<"\n station name ";
        cin>>a;
        t->stnm=a;
        cout<<"\n arrival time ";
        cin>>a;
        t->arr=a;
        cout<<"\n departure time ";
        cin>>a;
        t->dept=a;
        cout<<"\n distance ";
        cin>>a;
        t->dist=a;

        cout<<"\n source station ";
        cin>>a;
        t->val=a;
        cout<<"\n source station name ";
        cin>>a;
        t->sourcestanm=a;
        cout<<"\n departure station ";
        cin>>a;
        t->deststa=a;
        cout<<"\n departure station name ";
        cin>>a;
        t->deststanm=a;
        
        t->next=NULL;   		


}// end of function

// hash function to calculate the slot for insertion
int hash(string a)
{

        //char ch=a[0];
        cout<<"\n jho character hai "<<a[0];
        int m=(int)a[0]; 
        int s=m%26;
        return s;   

}// end of function


// function to insert in the link list 
void insertmain(int i,string val)
{     
      
        if(top[i]==NULL)
            top[i]=t;
         else 
        {
           t->next=top[i];
           top[i]=t;

        }// end of else


}// end of function

//function to insert in the link list
void insert(string a)
{
        cout<<"\n the val is "<<a;
        int k=hash(a);
        cout<<"\n hash value "<<k; 
        insertmain(k,a);          

}// end of function

void printmain(node *top)
{
	
        if(top==NULL)
        {
            cout<<"\n empty \n";
            return ;
        }
        else
        {     

          ptr=top;
          while(ptr)
          { 
            cout<<ptr->val<<" ";
            ptr=ptr->next;
 
          }// end of while          
        }// end of else  

      cout<<"\n"; 
}// end of function

// separate printing function
void print()
{
        
	for(int i=0;i<25;i++)
        {
             cout<<"\n the "<<i<<" list is \n";               
             printmain(top[i]);
        }
    

}// end of function


// separate function for printing the values
void print2(node *p)
{
   cout<<p->no<<" "<<p->nm<<" "<<p->seq<<" "<<p->val<<" "<<p->deststa<<" "
   <<p->arr<<" "<<p->dept;
   cout<<"\n";    

}// end of function 


// searching function
void search(string val,string time1,string time2)
{
        
        int hk=hash(val),a[4],b[4];

        ptr=top[hk];

        while(ptr)
	{
                        

            if(ptr->arr>=time1&&ptr->arr<=time2||
              ( ptr->dept>=time1&&ptr->dept<time2)) 
               print2(ptr); 
            else     
              cout<<"\n nahi mila \n";
 
            ptr=ptr->next;
 
	}// end of while     


}// end of function



// setup function 
void setup(string v,string time)
{

     //search(v);
  
     int a[4],b[4];
     a[0]=(int)time[0]-48;
     a[1]=(int)time[1]-48;
     a[2]=(int)time[2]-48; 
     a[3]=(int)time[3]-48;

     cout<<"\n array a is ";
     for(int i=0;i<4;i++)
        cout<<a[i];

       
     // subtract 15 min and add 1 hour  
     for(int i=0;i<4;i++)
         b[i]=a[i];
     
     cout<<"\n array b is ";
     for(int i=0;i<4;i++)
        cout<<b[i];
  
     int i=3;
    // subtract 15 from the array
 
     while(i>=0)
     {
       if(i==3)
     {  
         a[i]=a[i]-0;

     }
     else
      if(i==2)
      {
        if(a[i]<3)
         {
             a[i]=a[i]+10;
             if(a[i-1]==0)
             {

                a[i-1]=a[i-1]+10;
                a[i-2]=a[i-2]-1;

             }
             else 
              a[i-1]--;

         } 
         else
           ; // do nothing  

         a[i]=a[i]-3;

      }// end of else  

      i--;

     }// end of while        

     // now add 1hr to a
     for(int i=0;i<4;i++)
         b[i]=a[i];

     b[1]++;
     cout<<"\n b[1] is" <<b[1];

     if(b[1]>9)
     {
       int h=b[1]/10;
       b[1]=b[1]%10;
       b[0]=b[0]+h;

     }
     else
       ; // do nothing         
     
     cout<<"\n array a is ";
     for(int i=0;i<4;i++)
        cout<<a[i];

     cout<<"\n array b is ";
     for(int i=0;i<4;i++)
        cout<<b[i];

     string time1,time2;

     time1[0]=a[0]+'0';
     time1[1]=a[1]+'0';   
     time1[2]=a[2]+'0';
     time1[3]=a[3]+'0';
    
     for(int i=0;i<4;i++)
     cout<<"\n time1 is"<<time1[i];
       
     cout<<"\n time1 is"<<time1;
     time2[0]=b[0]+'0';
     time2[1]=b[1]+'0';    
     time2[2]=b[2]+'0';
     time2[3]=b[3]+'0';
     
     std::cout<<"\n time2 is "<<time2;

     search(v,time1,time2);


}// end of function

int main()
{ 

          int j=0;        
          string line;
          ifstream data("railtime.csv",ios::in);
	  if(!data)
             cout<<"something wrong"<<endl; 
         

	  getline(data,line);
          cout<<line<<endl;
          // first input only 10 records
          while(getline(data,line) && j<=10) 
          {
               istringstream str(line);              
               string temp;          
               j++;  

              if(j==1)
             {
                getline(str,temp,',');
                getline(str,temp,',');
                getline(str,temp,',');

                getline(str,temp,',');
                getline(str,temp,',');
                getline(str,temp,',');

                getline(str,temp,',');
		getline(str,temp,',');
		getline(str,temp,',');

	        getline(str,temp,',');
                getline(str,temp,',');
                getline(str,temp,',');

 
             }
             else
            {

              t=new node;                
              t->next=NULL;   

              // train no 
              getline(str,temp,',');
              t->no=temp;

              // train name 
              getline(str,temp,',');
              t->nm=temp;

              // seq
              getline(str,temp,',');
              t->seq=temp;

              // station code
              getline(str,temp,',');
              t->code=temp;

              // station name
              getline(str,temp,',');
              t->stnm=temp;
 
              // arrival time  	      
              getline(str,temp,',');
              t->arr=temp;

              // departure time  
              getline(str,temp,',');
              t->dept=temp;

              //distance
              getline(str,temp,',');
              t->dist=temp;

              // source station
              getline(str,temp,',');
              t->val=temp;

              // source station name  
              getline(str,temp,',');
              t->sourcestanm=temp;

              //destination station 
              getline(str,temp,',');
              t->deststa=temp;

              // destination station name     
              getline(str,temp,',');
              t->deststanm=temp;      
         
              // node create karne ka kaam hua 
              insert(t->code); 
      
           }// end of else   
 
        }  // end of while
     
        print(); 
        string v,time;
        cout<<"\n enter the station code here ";     
        cin>>v;
        cout<<"\n enter the time here ";     
        cin>>time;
        setup(v,time);       
   /*          
        int i,jj;
        struct timespec start, stop;
        i=clock_gettime(CLOCK_REALTIME, &start);
        for (int i=0; i<1000; i++)
            for ( jj=0; jj<1000;j++);
             jj=clock_gettime(CLOCK_REALTIME, &stop);

        printf("%d, %d, %ld\n", i, jj, stop.tv_nsec - start.tv_nsec);
 */

}// end of code
