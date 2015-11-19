/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.vectoreditor;

import com.sun.prism.Graphics;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author Григорий
 */
public class MainFrame extends JFrame {

    private Canvas canvas;
    private Toolbar toolbar;
    

    MainFrame(String s) {
        super(s);
        canvas = new Canvas();
        toolbar = new Toolbar(canvas);
        setSize(800, 600);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        add(canvas, BorderLayout.CENTER);
        add(toolbar, BorderLayout.NORTH);
    }

}
