/*
    This is an addon to the decorator class that can be added
 */

/**
 *
 * @author aaron
 */
public class audioGuide extends addOn {

    public audioGuide(Tour newTour)
    {
        super(newTour);
    }
    @Override
    public String getDescription()
    {
        return tempTour.getDescription() + " An audio guide by curators and hosts ";
    }
    
    @Override
    public double getCost()
    {
        return tempTour.getCost() + 10;
    } 
    
    @Override
    public int getMinTimeInMinutes()
    {
        return tempTour.getMinTimeInMinutes() + 60;
    } 
    
    
    
}
