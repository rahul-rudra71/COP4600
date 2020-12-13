package edu.ufl.cise.os.ex4;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Ex4Activity extends Activity {

    private Button leftButton, rightButton;
    private EditText leftText, rightText;
    private ClipboardManager cbm;
    private ClipData cd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ex4);

        rightButton = (Button) findViewById(R.id.rightButton);
        leftButton = (Button) findViewById(R.id.leftButton);
        rightText = (EditText) findViewById(R.id.rightText);
        leftText = (EditText) findViewById(R.id.leftText);

        cbm = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
    }

    public void onLeftClick(View view)
    {
        // When the left button is clicked...
        String txt = leftText.getText().toString();
        cd = ClipData.newPlainText("Text",txt);
        cbm.setPrimaryClip(cd);
        ClipData newcd = cbm.getPrimaryClip();
        ClipData.Item item = newcd.getItemAt(0);
        String copyTxt = item.getText().toString();
        rightText.setText(copyTxt);
    }

    public void onRightClick(View view)
    {
        // When the right button is clicked...
        String txt = rightText.getText().toString();
        cd = ClipData.newPlainText("Text",txt);
        cbm.setPrimaryClip(cd);
        ClipData newcd = cbm.getPrimaryClip();
        ClipData.Item item = newcd.getItemAt(0);
        String copyTxt = item.getText().toString();
        leftText.setText(copyTxt);
    }
}
