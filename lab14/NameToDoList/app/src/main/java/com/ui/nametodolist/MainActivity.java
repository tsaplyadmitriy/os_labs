package com.ui.nametodolist;

import android.app.Dialog;
import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.View;

import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // получаем экземпляр элемента ListView
        ListView listView = (ListView) findViewById(R.id.listView);


        final ArrayList<String> tasks = new ArrayList<>();

        // Создаём адаптер ArrayAdapter, чтобы привязать массив к ListView
        final TaskAdapter adapter;
        adapter = new TaskAdapter(getBaseContext(),tasks);
        // Привяжем массив через адаптер к ListView
        listView.setAdapter(adapter);




        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final Dialog dialog = new Dialog(MainActivity.this);

                // Установите заголовок
                dialog.setTitle("Add task");
                // Передайте ссылку на разметку
                dialog.setContentView(R.layout.dialog_view);
                dialog.show();
                // Найдите элемент TextView внутри вашей разметки
                // и установите ему соответствующий текст
                final TextView text = (TextView) dialog.findViewById(R.id.editTextTextPersonName);
                Button add = (Button) dialog.findViewById(R.id.button);
                add.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        if(text.getText()!=""){


                        tasks.add(0,   text.getText().toString());
                        adapter.notifyDataSetChanged();
                        dialog.dismiss();

                        }
                    }
                });

            }
        });
    }




}