using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PetrolPump
{
    class Program
    {
       /* static int n=50;
        public int Find_answer(int[] litres)
        {
            return FindMin(Min_answer(litres, true, false, 0, 0, 0),Min_answer(litres,false,true,0,0,0));
        }
         int Min_answer(int[] litre,bool first,bool second,int vehicle,int first_time,int second_time)
        {
            if (vehicle == n-1)
            {
                if (first)
                    return first_time + litre[vehicle];
                else
                    return second_time + litre[vehicle];
            }
            return FindMin(Min_answer(litre, true, false,vehicle+1, first_time+litre[vehicle], second_time), Min_answer(litre, false, true, vehicle+1, first_time, second_time + litre[vehicle]));

             
        }
        int FindMin(int a,int b)
        {
            return a < b ? a : b;
        }*/
         static void Main(string[] args)
        {
            string data;
            data=Console.ReadLine();
            string[] values = data.Split(' ');
           
            int[] vehicles = new int[values.Length];
            int i = 0,sum=0;
            foreach(string v in values)
            {
                vehicles[i++] = int.Parse(v);
                sum += vehicles[i - 1];
            }
            Array.Sort(vehicles);
            Array.Reverse(vehicles);
            for (i=0;i<vehicles.Length;i++)
            {
                Console.Write(vehicles[i] + " ");
            }
            Console.WriteLine("\n"+sum);
            int n = values.Length;
            PumpDivider pumpDivider = new PumpDivider(n);
            //int ans=pumpDivider.Find_answer(vehicles);
            Console.WriteLine(pumpDivider.LeastTime(vehicles));
            
        }
    }
    class PumpDivider
    {
        readonly int n;
        //bool[] flag;
        public PumpDivider(int n)
        {
            this.n = n;
           /* flag = new bool[n];
            for (int i = 0; i < n; i++)
                flag[i] = false;*/
        }
        public int Find_answer(int[] litres)
        {
            return Min_answer(litres, 0, 0, 0);
        }
        int Min_answer(int[] litre, int vehicle, int first_time, int second_time)
        {
           if (vehicle == n - 1)
            {
                if (first_time<second_time)
                    first_time= first_time + litre[vehicle];
                else
                    second_time =  second_time + litre[vehicle];
                return first_time;
            }
          /* // first_time = Min_answer(litre, true, false, vehicle + 1, first_time + litre[vehicle], second_time);
           // second_time = Min_answer(litre, false, true, vehicle + 1, first_time, second_time + litre[vehicle])
            return FindMin(Min_answer(litre, true, false, vehicle + 1, first_time + litre[vehicle], second_time), Min_answer(litre, false, true, vehicle + 1, first_time, second_time + litre[vehicle]));*/

            if(first_time<second_time)
            {
                first_time = Min_answer(litre, vehicle + 1, first_time + litre[vehicle], second_time);
            }
            else
            {
                first_time = Min_answer(litre, vehicle + 1, first_time, second_time + litre[vehicle]);
            }
            return first_time;
            


        }
        int FindMin(int a, int b)
        {
            return a < b ? a : b;
        }
        int FindMax(int a,int b)
        {
            return a > b ? a : b;
        }
        public int LeastTime(int[] litre)
        {
            int sum1 = 0, sum2 = 0;
            for(int i=0;i<n;i++)
            {
                if (sum1 < sum2)
                    sum1 += litre[i];
                else
                    sum2 += litre[i];
            }
            Console.WriteLine((sum1 + sum2));
           return FindMax(sum1, sum2);
        }
    }
}
