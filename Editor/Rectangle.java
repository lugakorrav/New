/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.vectoreditor;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Григорий
 */
public class Rectangle extends Figure {

    public Rectangle() {
        super();
    }

    @Override
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.fillRect(0, 0, 100, 100);
    }
}
