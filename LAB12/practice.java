//CS20B1109
//Nischal Pradyoth
//implementing calculator program for simple expressions not for involving two or more operators.
//NOTE:Here I haven't done exception handling for division and modulo operators becuase there are already mentioned in java package.
//Please note the above conditions.
import java.applet.Applet;
import java.awt.event.*;
import java.awt.*;
import java.lang.*;

public class practice extends Applet implements ActionListener
{
    Button b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b,b11,b12,b13,b14,b15,b16;//Buttons
    TextField tf;
    String s;
    public void init()
    {
        setLayout(null);
        //setting locations for buttons
        b9=new Button("9");
        b9.setBounds(50,100,40,40);
        add(b9);

        b8=new Button("8");
        b8.setBounds(90,100,40,40);
        add(b8);

        b7=new Button("7");
        b7.setBounds(130,100,40,40);
        add(b7);

        b6=new Button("6");
        b6.setBounds(50,140,40,40);
        add(b6);

        b5=new Button("5");
        b5.setBounds(90,140,40,40);
        add(b5);

        b4=new Button("4");
        b4.setBounds(130,140,40,40);
        add(b4);

        b3=new Button("3");
        b3.setBounds(50,180,40,40);
        add(b3);

        b2=new Button("2");
        b2.setBounds(90,180,40,40);
        add(b2);

        b1=new Button("1");
        b1.setBounds(130,180,40,40);
        add(b1);

        b0=new Button("0");
        b0.setBounds(50,220,40,40);
        add(b0);

        b11=new Button("EST");
        b11.setBounds(130,220,40,40);
        add(b11);

        b12=new Button("ACT");
        b12.setBounds(170,100,40,40);
        add(b12);

        b13=new Button("Close");
        b13.setBounds(170,140,40,40);
        add(b13);

        b10=new Button("CET");
        b10.setBounds(210,180,40,40);
        add(b10);

        tf=new TextField();
        tf.setBounds(50,50,200,50);
        add(tf);
        //adding these buttons and text field
        b9.addActionListener(this);
        b8.addActionListener(this);
        b7.addActionListener(this);
        b6.addActionListener(this);
        b5.addActionListener(this);
        b4.addActionListener(this);
        b3.addActionListener(this);
        b2.addActionListener(this);
        b1.addActionListener(this);
        b0.addActionListener(this);
        b10.addActionListener(this);
        b11.addActionListener(this);
        b12.addActionListener(this);
        b13.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e)//Action listener
    {//checking which button is clicked and acting accordingly
        if(e.getSource()==b0)
        {
           s=tf.getText();
           tf.setText(s+"0");  
        }
        else if(e.getSource()==b1)
        {
            s=tf.getText();
            tf.setText(s+"1");
        }
        else if(e.getSource()==b2)
        {
            s=tf.getText();
            tf.setText(s+"2");
        }
        else if(e.getSource()==b3)
        {
            s=tf.getText();
            tf.setText(s+"3");
        }
        else if(e.getSource()==b4)
        {
            s=tf.getText();
            tf.setText(s+"4");
        }
        else if(e.getSource()==b5)
        {
            s=tf.getText();
            tf.setText(s+"5");
        }
        else if(e.getSource()==b6)
        {
            s=tf.getText();
            tf.setText(s+"6");
        }
        else if(e.getSource()==b7)
        {
            s=tf.getText();
            tf.setText(s+"7");
        }
        else if(e.getSource()==b8)
        {
            s=tf.getText();
            tf.setText(s+"8");
        }
        else if(e.getSource()==b9)
        {
            s=tf.getText();
            tf.setText(s+"9");
        }
        else if(e.getSource()==b10)
        {
            s=tf.getText();
            int first=s.indexOf(":");
            int second=s.lastIndexOf(":");
            if(first!=-1&&second!=-1){
                s=s.substring(0,first)+s.substring(first+1);
                s=s.substring(0,second-1)+s.substring(second);
            }
            String s1,s2,s3;
            s1=s.substring(0,2); s2=s.substring(2,4); s3=s.substring(4);
            int one=Integer.parseInt(s1); int two=Integer.parseInt(s2); int three=Integer.parseInt(s3);
            one-=4; two-=30; 
            if(one<0){one+=24;} 

            if(two<0){two+=60;}
            tf.setText(one+":"+two+":"+three);
        }
        else if(e.getSource()==b11)
        {
            s=tf.getText();
            int first=s.indexOf(":");
            int second=s.lastIndexOf(":");
            if(first!=-1&&second!=-1){
                s=s.substring(0,first)+s.substring(first+1);
                s=s.substring(0,second-1)+s.substring(second);
            }
            String s1,s2,s3;
            s1=s.substring(0,2); s2=s.substring(2,4); s3=s.substring(4);
            int one=Integer.parseInt(s1); int two=Integer.parseInt(s2); int three=Integer.parseInt(s3);
            one-=10; two-=50; 
            if(one<0){one+=24;} 

            if(two<0){two+=60;}
            tf.setText(one+":"+two+":"+three);
        }
        else if(e.getSource()==b12)
        {
            s=tf.getText();
            int first=s.indexOf(":");
            int second=s.lastIndexOf(":");
            if(first!=-1&&second!=-1){
                s=s.substring(0,first)+s.substring(first+1);
                s=s.substring(0,second-1)+s.substring(second);
            }
            String s1,s2,s3;
            s1=s.substring(0,2); s2=s.substring(2,4); s3=s.substring(4);
            int one=Integer.parseInt(s1); int two=Integer.parseInt(s2); int three=Integer.parseInt(s3);
            one-=5; two-=30; 
            if(one<0){one+=24;} 

            if(two<0){two+=60;}
            tf.setText(one+":"+two+":"+three);
        }
        else if(e.getSource()==b13)
        {
            System.exit(0);
        }
    }
}
/*
<applet code="practice.class" width="1028" height="2000">
</applet>
*/