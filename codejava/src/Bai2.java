import java.util.Scanner;

public class Bai2 {

    public static int[] inputArr()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap so phan tu mang: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i ++)
        {
            System.out.println("Nhap phan tu thu " + (i + 1) + ": ");
            a[i] = sc.nextInt();
        }
        return a;
    }

    public static int[] SapXep(int[] a)
    {
        for(int i = 0; i < a.length - 1; i ++)
        {
            for(int j = i + 1; j < a.length; j++)
            {
                if(a[i] > a[j])
                {
                    int tmp = a[i];
                    a[i] = a[j];    
                    a[j] = tmp;
                }
            }
        }
        return a;
    }
    
    public static void ouputArr(int[] a)
    {
        System.out.println("Mang sau khi sap xep: ");
        for(int i = 0; i < a.length; i ++)
        {
            System.out.print("a[" + i + "] = " + a[i] + " ");
        }
    }
    public static void main(String[] args)
    {
        int[] a = inputArr();
        a = SapXep(a);
        System.out.println("\nDS sau khi sap xep: ");
        ouputArr(a);
    }
}
