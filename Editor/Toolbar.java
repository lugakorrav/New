/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.vectoreditor;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JPanel;

/**
 *
 * @author Григорий
 */
public class Toolbar extends JPanel {

    Canvas canvas;

    public Toolbar(Canvas c) {
        canvas = c;
        JButton rectButton = new JButton("Прямоугольник");
        add(rectButton);
        ActionListener rectButtonListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Rectangle r = new Rectangle();
                canvas.addFigure(r);
                canvas.repaint();
            };
        };
        rectButton.addActionListener(rectButtonListener);
    }

}
