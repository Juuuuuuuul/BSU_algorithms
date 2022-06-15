import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static int n, m;
    public static int[][] arr;

    public static void sort(Main objk){

        for (int k = m - 1; k > 0; k--) {       // сортируем строки
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][j] < arr[i + 1][j]) {
                        objk.swp(arr[i], arr[i + 1]);
                        break;
                    }
                }
            }
        }
    }

    public void swp(int[] len1, int[] len2) {
        int[] buf = Arrays.copyOf(len1, len1.length);
        for (int i = 0; i < len1.length; i++) {
            len1[i] = len2[i];
            len2[i] = buf[i];
        }
    }

    public boolean cmp(int[] len1, int[] len2) {
        for (int i = 0; i < len1.length; i++) {
            if (len1[i] > len2[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream("output.txt");
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[m][n];

        int result = 0;
        int[] mas = new int[m]; // массив с количеством вмещений объектов друг в друга

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
            Arrays.sort(arr[i]); // сотрируем в строках
        }

        Main objk = new Main();
        sort(objk);

        for (int i = 0; i < m; i++) {
            mas[i] = 0;
        }

        for (int k = 0; k < m; k++) {
            for (int i = k - 1; i >= 0; i--) {
                if (objk.cmp(arr[k], arr[i]) == true) {
                    if (mas[i] + 1 > mas[k]) {
                        mas[k] = mas[i] + 1;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++){
            if (result < mas[i]){
                result = mas[i];
            }
        }
        result++;
        ps.println(result);
    }
}
