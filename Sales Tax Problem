using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace thoughtWorks_Prep
{

    public class item
    {
        private string entry;
        private double price;
        private int qty;
        private double totalPrice;
        private string name;
        public item(string entry)
        {
            string[] e = entry.Split(' ');//cause this works better for getting the number of items and the price of items
            this.entry = entry;
            this.qty = Convert.ToInt32(e[0]);
            this.price = Convert.ToDouble(e[e.Length-1]);
        }

        public int getNumerOfItems()
        {
            return this.qty;
        }

        public double getUnitPrice()
        {
            return price;
        }

        public bool isImported
        {
            get
            {
                return entry.IndexOf("imported") == -1 ? false : true;
            }
        }

        public bool noRegTax// no regular tax books, food, meds
        {
            get
            {
                if (entry.IndexOf("book") != -1)
                    return true;

                if (entry.IndexOf("chocolate") != -1)
                    return true;

                if (entry.IndexOf("pills") != -1)
                    return true;

                return false;
            }
        }

        public string getItemName()
        {
            this.name = "";
            string[] e = this.entry.Split(' ');
            for (int i = 1; i < e.Length - 2; i++)
            {
                this.name = this.name + e[i] + " ";
            }
            return this.name;
        }

        public double ComputeTotalPrice()
        {
            this.totalPrice = this.qty * this.price;
            return this.totalPrice;
        }

        public double salesTax()
        {
            double tax = 0.0;
            double total = this.ComputeTotalPrice();
            if (this.isImported)
            {
                tax = tax + (0.05 * total);
            }
            if (!this.noRegTax)
            {
                tax = tax + (.10 * total);
            }
            return this.round(tax);
        }

        public double round(double n)
        {
            double v = Math.Ceiling(n*20);
            return v / 20;
        }

        public double taxPlusPrice()
        {
            return (this.salesTax() + this.ComputeTotalPrice());
        }
    }
    public class sales
    {
        private List<string> input;
        private List<string> output;
        public sales(List<string> input)
        {
            this.input = input;
            this.output = new List<string>();
        }

        public void processInput()
        {
            string numItems;
            string nameOfItem;
            double totalPrice = 0;
            double unitPrice;
            double salesTax = 0;
            for (int i = 0; i < input.Count; i++)
            {
                item entry = new item(input[i]);

                numItems = entry.getNumerOfItems().ToString();
                nameOfItem = entry.getItemName();
                
                unitPrice = entry.taxPlusPrice();

                this.output.Add(numItems +" " + nameOfItem + "at " + unitPrice);
                salesTax += entry.salesTax();
                totalPrice += entry.taxPlusPrice();
            }
            this.output.Add("Sales Tax: " + salesTax);
            this.output.Add("Total: " + totalPrice);
        }

        public List<string> returnOutput()
        {
            for (int i = 0; i < this.output.Count(); i++)
            {
                Console.WriteLine(this.output[i]);
            }
            return this.output;
        }                
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, please enter a file path");
            Console.WriteLine("if you do not enter one, the default input file in the {0} folder will be chosen will be chosen", Environment.CurrentDirectory);
            string input = Console.ReadLine();

            

            if (input == "" || !File.Exists(input))
            {
                Console.WriteLine("you either didn't enter a file name, or entered the path incorrectly");
                Console.WriteLine("program will use the default input found in {0}", Environment.CurrentDirectory);
                input = "input.txt";
            }

            Console.WriteLine();

            try
            {
                StreamReader sr = new StreamReader(@input);


                string data = "";
                List<string> myList = new List<string>();
                Console.WriteLine("Input: ");
                while (!sr.EndOfStream)
                {
                    data = sr.ReadLine();
                    myList.Add(data);
                    Console.WriteLine(data);
                }
                Console.WriteLine();

                sales obj = new sales(myList);
                obj.processInput();
                Console.WriteLine("Output: ");
                List<string> output = obj.returnOutput();

                Console.WriteLine();
                Console.WriteLine("Please specify a directory to write to: ");
                string outputFile = Console.ReadLine();


                if (outputFile == "" || !File.Exists(outputFile))
                {
                    Console.WriteLine("you either didn't enter a file name, or entered the path incorrectly");
                    Console.WriteLine("program will write to the default file (output.txt) in {0}", Environment.CurrentDirectory);
                    outputFile = "output.txt";
                }
                Console.WriteLine();

                StreamWriter sw = new StreamWriter(outputFile);
                
                for (int i = 0; i < output.Count; i++)
                {
                    sw.WriteLine(output[i]);
                }
                sw.Close();
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("File Not Found Exception, program will terminate");
                Console.WriteLine("Please enter valid file paths, or insert an input.txt file into the {0} directory", Environment.CurrentDirectory);
            }

            Console.WriteLine("Exiting program");
            Console.ReadLine();
        }
    }
}
