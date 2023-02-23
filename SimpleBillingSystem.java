import java.util.*;

class SimpleBillingSystem {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String Item_name[] = new String[20];
    int Item_price[] = new int[10];
    int Quantity[] = new int[10];
    int Price[] = new int[5];
    int i = 0, check = 1, total = 0;
    welcomeNote();
    System.out.println("1. Generate Invoice\n0. Exit\n=> ");
    int option = sc.nextInt();
    switch (option) {
      case 1:
        while (check != 0) {
          System.out.print("\n------------------------------");
          System.out.print("\nItem: " + (i + 1));
          System.out.print("\nProduct Name: ");
          Item_name[i] = sc.next();
          System.out.print("Quantity: ");
          Quantity[i] = sc.nextInt();
          System.out.print("Price: ");
          Price[i] = sc.nextInt();
          Item_price[i] = Quantity[i] * Price[i];
          System.out.print("------------------------------\n");
          System.out.print("\n1. Add another item\n0. Checkout\n=> ");
          check = sc.nextInt();
          i++;
        }
        sc.close();

        InvoiceTop();
        for (int j = 0; j < i; j++) {
          System.out.print(j + 1);
          System.out.print(" \t" + Item_name[j]);
          System.out.print("\t" + Quantity[j]);
          System.out.print("\t" + Price[j]);
          System.out.println("\t" + Item_price[j]);
          total += Item_price[j];
        }

        System.out.println("--------------------------------------");
        System.out.print("\t\t\t Total : " + total + " Tk\n\n");
        thankYou();
        break;
      case 0:
        thankYou();
        break;
      default:
        invalid();
        break;
    }
  }

  public static void welcomeNote() {
    System.out.println("\n======================================");
    System.out.println("\tWelcome to Super Shop");
    System.out.println("======================================\n");
  }

  public static void InvoiceTop() {
    System.out.print("\n\n======================================");
    System.out.print("\n\t\tInvoice");
    System.out.print("\n======================================\n");
    System.out.print("\n--------------------------------------\n");
    System.out.print("\tItem");
    System.out.print("\tQty");
    System.out.print("\tRate");
    System.out.print("\tPrice");
    System.out.print("\n--------------------------------------\n");
  }

  public static void thankYou() {
    System.out.print("\t   -------------\n");
    System.out.print("\t   | Thank you |\n");
    System.out.print("\t   -------------\n\n\n");
  }

  public static void invalid() {
    System.out.print("\t---------------------------\n");
    System.out.print("\t| Invalid option selected |\n");
    System.out.print("\t---------------------------\n\n\n");
  }
}
