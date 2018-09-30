using System;

namespace SeriesCalculator
{
    class Program
    {
        private static string option = "0";

        public static void Main(string[] args)
        {
            do
            {

                Console.WriteLine("------------------------------");
                Console.WriteLine("*  Escolha o tipo de serie:  *");
                Console.WriteLine("------------------------------");
                Console.WriteLine("1: Harmonica");
                Console.WriteLine("2: ...");
                Console.WriteLine("0: SAIR");
                option = Console.ReadLine();
                Console.Clear();
                switch (option)
                {
                    case "1":
                        Console.WriteLine("1: A série Harmonica é " + DeterminarConvergenciaHarmonica());
                        Console.Clear();
                        break;

                    case "2":
                        Console.WriteLine("2: Soma serie:");
                        Console.WriteLine("Enter the value of n:");
                        String Sum2Answer = Console.ReadLine();
                        Console.WriteLine("Result with n=" + Sum2Answer + " is " + Sum2(Int32.Parse(Sum2Answer)));
                        Console.WriteLine("ENTER TO CONTINUE");
                        Console.ReadLine();
                        Console.Clear();
                        break;

                    case "0":
                        break;

                    default:
                        Console.WriteLine("Available options: 1 or 2!");
                        Console.WriteLine("ENTER TO CONTINUE");
                        Console.ReadLine();
                        Console.Clear();
                        break;
                }
                
                

            } while (option != "0");
        }


        public static float DeterminarConvergenciaHarmonica()
        {
            float soma = 1;
            Int64 ateInfinito = 99999;

            for (var i = 2; i < ateInfinito; i++)
            {
                float k = (1 / i);
                soma += k;
            }
            return soma;
        }

        public static Int64 Factorial(Int64 number)
        {
            if (number <= 2)
                return number;
            else
                return number * Factorial(number - 1);
        }

        public static Int64 Sum2(int n) {
            int i, k;
            Int64 s = 0;

            k = n;
            s = 1 / n;

            for (i = 2; i < n; i++)
            {
                k--;
                s += i / k;
            }

            return s;
        }

    }
}
