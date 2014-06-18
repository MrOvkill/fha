/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.2.0
    * Date: 06/18/2014

*/

package com.epicknife.fha;

import java.util.Random;

public class Fha
{
    private Random rand;
    private char[] str;
    
    private int randr(int min, int max)
    {
        return (33+rand.nextInt(123-33));
    }
    
    public Fha(char[] file)
    {
        str = file;
    }
    
    public char[] hash()
    {
        char[] hsh = new char[str.length];
        
        int stc = 0;
        
        for(int i = 0; i < str.length; i++)
        {
            stc += (str[i]*i);
        }
        
        while(stc < 100000)
        {
            stc -= 50;
        }
        
        rand = new Random(stc+str.length);
        rand.setSeed(stc+str.length);
        
        for(int i = 0; i < str.length; i++)
        {
            hsh[i] = (char)randr(33, 123);
        }
        
        return hsh;
    }
    
    public void close()
    {
        rand = null;
        str = null;
    }
}
