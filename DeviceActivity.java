package devrss.hmtri.vn.module;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import devrss.hmtri.vn.envparob.R;

public class DeviceActivity extends AppCompatActivity {
    Button Tb1, Tb2, Tb3;
    boolean onoff = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_device);
        CtrolDevice();
        AddCtrolDevice();
    }

    public void CtrolDevice(){
        Tb1 = (Button)findViewById(R.id.bt1);
        Tb2 = (Button)findViewById(R.id.bt2);
        Tb3 = (Button)findViewById(R.id.bt3);
    }
    public void AddCtrolDevice(){
        Tb1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(onoff == false){
                    Tb1.setBackgroundResource(R.drawable.toggle_on);
                    Toast.makeText(getApplicationContext(), "ON", Toast.LENGTH_SHORT).show();
                    onoff = true;
                }
                else {
                    Tb1.setBackgroundResource(R.drawable.toggle_off);
                    Toast.makeText(getApplicationContext(), "OFF", Toast.LENGTH_SHORT).show();
                    onoff = false;
                }

            }
        });

        Tb2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(onoff == false){
                    Tb2.setBackgroundResource(R.drawable.toggle_on);
                    Toast.makeText(getApplicationContext(), "ON", Toast.LENGTH_SHORT).show();
                    onoff = true;
                }
                else {
                    Tb2.setBackgroundResource(R.drawable.toggle_off);
                    Toast.makeText(getApplicationContext(), "OFF", Toast.LENGTH_SHORT).show();
                    onoff = false;
                }

            }
        });

        Tb3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(onoff == false){
                    Tb3.setBackgroundResource(R.drawable.toggle_on);
                    Toast.makeText(getApplicationContext(), "ON", Toast.LENGTH_SHORT).show();
                    onoff = true;
                }else {
                    Tb3.setBackgroundResource(R.drawable.toggle_off);
                    Toast.makeText(getApplicationContext(), "OFF", Toast.LENGTH_SHORT).show();
                    onoff = false;
                }

            }
        });
    }



}
