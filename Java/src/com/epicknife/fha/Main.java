/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.2.0
    * Date: 06/18/2014

*/

package com.epicknife.fha;

import java.util.ArrayList;
import java.io.*;

public class Main
{
    private static boolean ivc(char c)
    {
        for(int i = 33; i < 123; i++)
        {
            if(c == i)
            {
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) throws Exception
    {
        if(args.length < 1)
        {
            System.out.println("Usage: fha.jar <file>");
        }
        else
        {
            File f = new File(args[0]);
            if(!f.exists())
            {
                System.exit(1);
            }
            char[] chars = new char[(int)f.length()*8];
            InputStreamReader isr = new InputStreamReader(new FileInputStream(f));
            char c;
            int i = 0;
            while((c = (char)isr.read()) != 0xFFFF)
            {
                chars[i] = c;
                i++;
            }
            isr.close();
            Fha fha = new Fha(chars);
            System.out.println(new String(fha.hash()));
            fha.close();
        }
    }
}
