package devrss.hmtri.vn.module;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

import devrss.hmtri.vn.envparob.R;
import devrss.hmtri.vn.weather.WeatherActivity;

public class MainActivity extends AppCompatActivity {
    FloatingActionButton fab, fab_setting, fab_device, fab_about;
    boolean showhide = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fab = (FloatingActionButton) findViewById(R.id.fab);
        fab_setting = (FloatingActionButton) findViewById(R.id.fab_setting);
        fab_device = (FloatingActionButton) findViewById(R.id.fab_device);
        fab_about = (FloatingActionButton) findViewById(R.id.fab_about);


        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(showhide == false){
                    showfab();
                    showhide = true;
                }else {
                    hidefab();
                    showhide = false;
                }
            }
        });

        fab_setting.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intensetting = new Intent(MainActivity.this, WeatherActivity.class);
                startActivity(intensetting);
            }
        });

        fab_device.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent iDevice = new Intent(MainActivity.this, DeviceActivity.class);
                Toast.makeText(MainActivity.this, "Device", Toast.LENGTH_SHORT).show();
                startActivity(iDevice);
                finish();
            }
        });

        fab_about.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "About", Toast.LENGTH_SHORT).show();
            }
        });
    }
    private void showfab(){
        fab_setting.show();
        fab_device.show();
        fab_about.show();
    }
    private void hidefab(){
        fab_setting.hide();
        fab_device.hide();
        fab_about.hide();
    }
}
