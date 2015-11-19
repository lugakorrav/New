/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.vectoreditor;

import java.awt.Graphics;
import java.awt.Color;
import java.util.LinkedList;
import javax.swing.JPanel;

/**
 *
 * @author Григорий
 */
public class Canvas extends JPanel {

    LinkedList<Figure> Figures;

    public Canvas() {
        setBackground(Color.white);
    }

    public void paint(Graphics g) {
        super.paint(g);
//        for (Figure element : Figures) {
//            if (element != null) {
//                element.paint(g);
//            }
            System.out.println("dasdasd");
            Figures.getFirst().paint(g);
    }

    public void addFigure(Figure f) {
        Figures.addFirst(f);
    }
}
