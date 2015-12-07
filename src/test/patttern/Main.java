package test.patttern;

import com.sun.jna.Structure;
import net.patttern.WkHtmlToXWarapper;
import net.patttern.classes.PdfGlobal;
import net.patttern.classes.PdfObject;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * Created by ebabenko on 27.08.15.
 */
public class Main {
  public static void main(String[] args) {
    WkHtmlToXWarapper htx = new WkHtmlToXWarapper();
    System.out.println(htx.init(0));
    System.out.println(htx.version());
    System.out.println(htx.extended());
    System.out.println(htx.deinit());

    PdfGlobal gSettings = htx.createGlobalSettings();
    System.out.println(gSettings);
    htx.destroyGlobalSettings(gSettings);
    System.out.println("PdfGlobal was destroyed");

//    PdfObject oSettings = htx.createObjectSettings();
//    System.out.println(oSettings);
//    htx.destroyObjectSettings(oSettings);
//    System.out.println("PdfObject was destroyed");
  }
}
