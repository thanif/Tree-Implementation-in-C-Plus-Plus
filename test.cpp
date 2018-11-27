
#include "helper.h"

unsigned long ms = 0; // for calculating sales of a month

unsigned long ds = 0; // for calculating sales of a day

unsigned long RecurseTotalMonthSales(TreeNode<unsigned long>* p)
{
   if (p == NULL) 
   {
   
   	
        return ms; 
   }
   

   RecurseTotalMonthSales(p->GetFirstChild());  
  
  
   RecurseTotalMonthSales(p->GetNextSibling()); 
  
        if (p->GetFirstChild() == NULL)
  	{
  		ms = ms + p->GetValue();
  		
  		
  	}

}

unsigned long TotalMonthSales(unsigned long year, unsigned long month, Tree<unsigned long>& t)
{
	TreeNode<unsigned long>* r = t.Root();
	TreeNode<unsigned long>* y = t.SearchChildren(r,year);
	if (y != NULL)
	{
		TreeNode<unsigned long>* m = t.SearchChildren(y,month);
		
		if (m != NULL)
		{
		
			unsigned long s = RecurseTotalMonthSales(m);
			
			return ms;
			
		}
		else
		
		{
			cout<<"Month not found "<< endl;
		}
	}
	
	else
	{
		cout<<"Year not found "<<endl;
	}			
}

unsigned long RecurseTotalDaySales(TreeNode<unsigned long>* p)
{   

   if (p == NULL) 
   {
   
   	
        return ds; 
   }
   

  RecurseTotalDaySales(p->GetFirstChild());  
  
  

   
  RecurseTotalDaySales(p->GetNextSibling()); 
  
        if (p->GetFirstChild() == NULL)
  	{
  		ds  = ds + p->GetValue();
  		
  		
  	}
	

   	
}

unsigned long TotalDaySales(unsigned long year, unsigned long month, unsigned long day, Tree<unsigned long>& t)
{
	TreeNode<unsigned long>* r = t.Root();
	TreeNode<unsigned long>* y = t.SearchChildren(r,year);
	
	
	
	if (y != NULL)
	{
		TreeNode<unsigned long>* m = t.SearchChildren(y,month);
		
		
		
		if (m != NULL)
		{
			TreeNode<unsigned long>* d = t.SearchChildren(m,day);
			
			
			
			if (d != NULL)
			{
				unsigned long s = RecurseTotalDaySales(d);
				
				
				
				return ds;
			}
			
			else
			
			{
				cout<< "Day not found"<<endl;
			}
			
		}
		else
		
		{
			cout<<"Month not found "<< endl;
		}
	}
	
	else
	{
		cout<<"Year not found "<<endl;
	}
}

void test_tiny_tree()
{
	cout << " ==============================================" << endl;
	cout << "|           Testing on a tiny tree             |" << endl;
	cout << " ==============================================" << endl;
	Tree<unsigned int> t2;
	TreeNode<unsigned int>* p1, *p2, *p3;
	t2.InsertRootNode(1);
	p1 = t2.InsertChild(t2.Root(), 2);
	p2 = t2.InsertChild(t2.Root(), 3);
	p3 = t2.InsertChild(t2.Root(), 4);
	t2.InsertChild(p1, 5);
	t2.InsertChild(p1, 6);
	t2.InsertChild(p2, 7);
	t2.InsertChild(p2, 8);
	t2.InsertChild(p3, 9);
	t2.InsertChild(p3, 10);
	t2.PreOrder();
}

void test_tiny_sales()
{
	cout << " ==============================================" << endl;
	cout << "|           Testing on sales data              |" << endl;
	cout << " ==============================================" << endl;
	Tree<unsigned long> t;
	if (ReadFile("tiny.csv", t))
	{
		t.PreOrder();
		unsigned long year = 2010;
		unsigned long month = 2;
		unsigned long day = 5;
		unsigned long sales = TotalDaySales(year, month, day, t);
		cout << "Total sales for year " << year << " month " << month << " and day " << day << " is " << sales << endl;
		sales = TotalMonthSales(year, month, t);
		cout << "Total sales for year " << year << " month " << month << " is " << sales << endl;
	}
	else
		cout << "Unable to load file into tree!" << endl;
}

int main()
{
	test_tiny_tree();
	test_tiny_sales();	
	return 0;	
}
