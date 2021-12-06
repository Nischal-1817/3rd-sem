//CS20B1109
//Nischal Pradyoth
//implementing calculator program for simple expressions not for involving two or more operators.
//NOTE:Here I haven't done exception handling for division and modulo operators becuase there are already mentioned in java package.
//Please note the above conditions.
import java.applet.Applet;
import java.awt.event.*;
import java.awt.*;
import java.lang.*;

public class calculator extends Applet implements ActionListener
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

        b=new Button(".");
        b.setBounds(90,220,40,40);
        add(b);

        b11=new Button("C");
        b11.setBounds(130,220,40,40);
        add(b11);

        b12=new Button("/");
        b12.setBounds(170,100,40,40);
        add(b12);

        b13=new Button("*");
        b13.setBounds(170,140,40,40);
        add(b13);

        b14=new Button("-");
        b14.setBounds(170,180,40,40);
        add(b14);

        b15=new Button("+");
        b15.setBounds(170,220,40,40);
        add(b15);

        b16=new Button("=");
        b16.setBounds(210,220,40,40);
        add(b16);

        b10=new Button("%");
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
        b.addActionListener(this);
        b0.addActionListener(this);
        b10.addActionListener(this);
        b11.addActionListener(this);
        b12.addActionListener(this);
        b13.addActionListener(this);
        b14.addActionListener(this);
        b15.addActionListener(this);
        b16.addActionListener(this);
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
            tf.setText(s+"%");
        }
        else if(e.getSource()==b)
        {
            s=tf.getText();
            tf.setText(s+".");
        }
        else if(e.getSource()==b12)
        {
            s=tf.getText();
            tf.setText(s+"/");
        }
        else if(e.getSource()==b13)
        {
            s=tf.getText();
            tf.setText(s+"*");
        }
        else if(e.getSource()==b14)
        {
            s=tf.getText();
            tf.setText(s+"-");
        }
        else if(e.getSource()==b15)
        {
            s=tf.getText();
            tf.setText(s+"+");
        }
        else if(e.getSource()==b11)
        {
            tf.setText("");
        }
        else if(e.getSource()==b16)//evaluating
        {
            s=tf.getText();
            int index=0;
            int plus=s.lastIndexOf("+");//checking which operator is present
            int minus=s.lastIndexOf("-");
            int divi=s.lastIndexOf("/");
            int mul=s.lastIndexOf("*");
            int mod=s.lastIndexOf("%");
            if(minus!=-1){index=minus;}
            if(plus!=-1){index=plus;}
            if(divi!=-1){index=divi;}
            if(mul!=-1){index=mul;}
            if(mod!=-1){index=mod;}
            
            if(index==0)
            {
                tf.setText(s);
            }
            else 
            {
                float result=0;
                try 
                {
                    char c=s.charAt(index);
                    String s1=s.substring(0,index);
                    String s2=s.substring(index+1);
                    float one=Float.parseFloat(s1);//getting two float numbers from expression
                    float two=Float.parseFloat(s2);
                    switch(c)
                    {
                        case '+':
                            result=one+two;
                            break;
                        case '-':
                            result=one-two;
                            break;
                        case '/':
                            result=one/two;
                            break;
                        case '*':
                            result=one*two;
                            break;
                        case '%':
                            result=one%two;
                            break;
                        default:
                            tf.setText("Error");
                    }  
                    s=Float.toString(result);//printing result in text field
                    tf.setText(s); 
                }
                catch(Exception e2)//for any exception which is a wrong expression
                {
                    tf.setText("Error");
                }
            }   
        }
    }
}
/*
<applet code="calculator.class" width="600" height="600">
</applet>
*/