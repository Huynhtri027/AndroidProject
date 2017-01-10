package devrss.hmtri.vn.module;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.Button;

import devrss.hmtri.vn.envparob.R;

public class DeviceActivity extends AppCompatActivity {
    Button Tb1, Tb2, Tb3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_device);
    }

    public void CtrolDevice(){
        Tb1 = (Button)findViewById(R.id.bt1);
        Tb2 = (Button)findViewById(R.id.bt2);
        Tb3 = (Button)findViewById(R.id.bt3);
    }



}
