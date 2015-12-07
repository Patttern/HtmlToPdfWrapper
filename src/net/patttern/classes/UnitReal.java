package net.patttern.classes;

import com.sun.jna.Structure;
import net.patttern.enums.Pair;
import net.patttern.enums.Unit;

import java.util.Map;

/**
 * Created by ebabenko on 07.12.15.
 */
public class UnitReal extends Structure {
/*
  QPair<qreal, QPrinter::Unit> UnitReal;
*/
  public Pair pair;

  public UnitReal() {
  }
}
