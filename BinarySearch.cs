using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace searchAlgorithm1
{
    class Program
    {
        static void Main(string[] args)
        {
            int [] temp = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


            for (int i = 0; i < temp.Length; i++)
                Console.Write(temp[i] + " ");
            int top = 0;
            int bottom = temp.Length - 1;
            Console.WriteLine();
            Console.WriteLine(bottom);
            int key = 4;
            Console.WriteLine();

            binSearch(key, temp, top, bottom);

                Console.ReadKey();
        }

        public static void binSearch(int key, int[] list, int top, int bottom)
        {
            int mid = (top + bottom) / 2;
            if (key == list[mid])
            {
                Console.WriteLine(key + " found at location " + mid);
            }
            else if (key < list[mid])
            {
                bottom = mid;
                mid = (top + mid) / 2;
                binSearch(key, list, top, bottom); 
            }
            else if (key > list[mid])
            {
                top = mid+1;
                mid = (mid + bottom) / 2;
                binSearch(key, list, top, bottom);
            }
        }

       /* public static int linearSearch(int key, int[] list)
        {
            int temp = list[0];
            for (int i = 0; i < list.Length; i++)
            {
                if(key == list[i])
                    return
            }
        }*/
    }
}
