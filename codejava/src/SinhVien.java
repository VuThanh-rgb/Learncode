import java.util.*;

public class SinhVien {
    private String maSV;
    private String Ten;
    private float diemLT;
    private float diemTH;

    public String getMaSV()
    {
        return maSV;
    }

    public String getTen()
    {
        return Ten;
    }

    public float getDiemLT()
    {
        return diemLT;
    }   

    public float getDiemTH()
    {
        return diemTH;
    }   

    public float getDiemTB()
    {
        return diemTB();
    }


    public void setmaSV(String maSV)
    {
        this.maSV = maSV;
    }

    public void setTen(String Ten)
    {
        this.Ten = Ten;
    }

    public boolean setdiemLT(float diemLT)
    {
        if(diemLT < 0 || diemLT > 10)
        {
            System.out.println("Diem khong hop le. Vui long nhap lai!");
            return false;
        }
        else
            this.diemLT = diemLT;
        return true;
    }

    public boolean setdiemTH(float diemTH)
    {
        if(diemTH < 0 || diemTH > 10)
        {
            System.out.println("Diem khong hop le. Vui long nhap lai!");
            return false;
        }
        else
            this.diemTH = diemTH;
        return true;
    }

    public float diemTB()
    {
        return (this.diemLT + this.diemTH)/2;
    }

    public static void main(String[] args) {
        SinhVien sv = new SinhVien();
        Scanner sc = new Scanner(System.in);

        System.out.println("Nhap ma sinh vien: ");
            sv.setmaSV(sc.nextLine());

        System.out.println("Nhap ten sinh vien: ");
            sv.setTen(sc.nextLine());

        System.out.println("Nhap diem LT: ");
        if(!sv.setdiemLT(sc.nextFloat()))
        {
            sv.setdiemLT(sc.nextFloat());
        }

        System.out.println("Nhap diem TH: ");
        if(!sv.setdiemTH(sc.nextFloat()))
        {
            sv.setdiemTH(sc.nextFloat());
        }

        System.out.println("Thong tin sinh vien: ");

        System.out.println("Ma SV: " + sv.getMaSV());
        System.out.println("Ten SV: " + sv.getTen());
        System.out.println("Diem LT: " + sv.getDiemLT());
        System.out.println("Diem TH: " + sv.getDiemTH());

        System.out.println("Diem TB: " + sv.getDiemTB());
    }

}
