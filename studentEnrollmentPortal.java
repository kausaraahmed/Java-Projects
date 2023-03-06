import java.util.*;

public class studentEnrollmentPortal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        welcomeNote();
        System.out.print("--------------------------------------\n");
        System.out.print("Enter Your name: ");
        String name = sc.next();
        System.out.print("--------------------------------------\n");

        // Admission year
        System.out.print("\n--------------------------------------\n");
        System.out.print("Enter Admission year: ");
        int year = sc.nextInt();
        System.out.print("--------------------------------------\n");
        int roll = year % 100;

        // Semester Selection
        System.out.println("\n\t    Select Semester");
        System.out.print("======================================\n");
        System.out.println("1. Spring\t2. Summer\t3. Fall");
        System.out.print("\n=> ");
        int semester = sc.nextInt();
        System.out.print("--------------------------------------\n");
        switch (semester) {
            case 1:
                roll = (roll * 10) + 1;
                break;
            case 2:
                roll = (roll * 10) + 2;
                break;
            case 3:
                roll = (roll * 10) + 3;
                break;
            default:
                System.out.println("Warning!! Choose semester correctly.");
        }

        // Major Selection
        System.out.println("\n\t    Select Major");
        System.out.print("======================================\n");
        System.out.println("1. Bangla\t2. English\t3. BBA\n4. CSE\t\t5. MSJ");
        System.out.print("\n=> ");
        int major = sc.nextInt();
        System.out.print("--------------------------------------\n");
        switch (major) {
            case 1:
                roll = (roll * 1000) + 013;
                break;
            case 2:
                roll = (roll * 1000) + 014;
                break;
            case 3:
                roll = (roll * 1000) + 015;
                break;
            case 4:
                roll = (roll * 1000) + 016;
                break;
            case 5:
                roll = (roll * 1000) + 017;
                break;
            default:
                System.out.print("Warning!! Choose semester correctly.");
        }
        sc.close();

        // Random Roll generate
        roll = (roll * 1000) + random.nextInt(300);
        System.out.print("\n--------------------------------------\n");
        System.out.println("Congrats " + name + ". Your roll: " + roll);
        System.out.print("--------------------------------------\n\n");

    }

    public static void welcomeNote() {
        System.out.println("\n==============================================");
        System.out.println("\tULAB Student Enrollment Portal");
        System.out.println("==============================================\n");
    }
}